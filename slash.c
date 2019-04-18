#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <getopt.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "systeminfo.h"
#include "definitions.h"
#include "logos.h"
#include "asprintf.h"

// Now, some globals we'll *probably* need to use.
char hostname[HOST_NAME_MAX];
char *user;
char *gpu_string;
char *wm_string;
char *shell_string;
char *uptime_string;
char *memory_string;
char *cpu_string;
char *pkg_string;
char *model_string;
char *resolution_string;
char *distro_string;
char *gtk_string;
char *terminal_type;
struct utsname unameData;

void string_replacer(char **str, char *symbol, char *color){
    if (strstr(*str, symbol))
        *str = replace_str(*str, symbol, color);
}

void free_globals(void){
    free(gpu_string);
    free(cpu_string);
    free(wm_string);
    free(distro_string);
    free(resolution_string);
    free(uptime_string);
    free(shell_string);
    free(memory_string);
    free(model_string);
    free(pkg_string);
}

void safe_exit(int status){
    free_globals();
    exit(status);
}

void string_fill(char **str){
    // Add light foreground color escape sequences.
    string_replacer(str, "?lq", LIGHT_GRAY);
    string_replacer(str, "?lb", LIGHT_BLUE);
    string_replacer(str, "?lr", LIGHT_RED);
    string_replacer(str, "?lc", LIGHT_CYAN);
    string_replacer(str, "?ly", LIGHT_YELLOW);
    string_replacer(str, "?lm", LIGHT_MAGENTA);

    // Now, add normal foreground color escape sequences.
    string_replacer(str, "?b", BLUE);
    string_replacer(str, "?r", RED);
    string_replacer(str, "?l", BLACK);
    string_replacer(str, "?q", DARK_GRAY);
    string_replacer(str, "?w", WHITE);
    string_replacer(str, "?c", CYAN);
    string_replacer(str, "?y", YELLOW);
    string_replacer(str, "?m", MAGENTA);
    string_replacer(str, "?d", DEFAULT);

    // Add light background color escape sequences.
    string_replacer(str, "/lb", BG_LIGHT_BLUE);
    string_replacer(str, "/lg", BG_LIGHT_GREEN);
    string_replacer(str, "/lr", BG_LIGHT_RED);
    string_replacer(str, "/lc", BG_LIGHT_CYAN);
    string_replacer(str, "/ly", BG_LIGHT_YELLOW);
    string_replacer(str, "/lm", BG_LIGHT_MAGENTA);
    string_replacer(str, "/lq", BG_LIGHT_GRAY);

    // Then, add background color escape sequences.
    string_replacer(str, "/b", BG_BLUE);
    string_replacer(str, "/g", BG_GREEN);
    string_replacer(str, "/r", BG_RED);
    string_replacer(str, "/l", BG_BLACK);
    string_replacer(str, "/c", BG_CYAN);
    string_replacer(str, "/y", BG_YELLOW);
    string_replacer(str, "/m", BG_MAGENTA);
    string_replacer(str, "/w", BG_WHITE);
    string_replacer(str, "/q", BG_DARK_GRAY);
    string_replacer(str, "/d", BG_DEFAULT);

    /* Look for special info symbols. */
    if (strstr(*str, "\%host")){
        gethostname(hostname, HOST_NAME_MAX);
        *str = replace_str(*str, "\%host", hostname);
    }
    if (strstr(*str, "\%user")){
        user = getlogin();
        *str = replace_str(*str, "\%user", user);
    }
    if (strstr(*str, "\%kernel")){
        uname(&unameData);
        *str = replace_str(*str, "\%kernel", unameData.release);
    }
    if (strstr(*str, "\%gpu")){
        get_gpu(&gpu_string);
        *str = replace_str(*str, "\%gpu", gpu_string);
    }
    if (strstr(*str, "\%l-cpu")){
        get_cpu_model(0, &cpu_string);
        *str = replace_str(*str, "\%l-cpu", cpu_string);
    }
    if (strstr(*str, "\%cpu")){
        get_cpu_model(1, &cpu_string);
        *str = replace_str(*str, "\%cpu", cpu_string);
    }
    if (strstr(*str, "\%s-cpu")){
        get_cpu_model(2, &cpu_string);
        *str = replace_str(*str, "\%s-cpu", cpu_string);
    }
    if (strstr(*str, "\%ls-uptime")){
        get_uptime(0, &uptime_string);
        *str = replace_str(*str, "\%ls-uptime", uptime_string);
    }
    if (strstr(*str, "\%lm-uptime")){
        get_uptime(1, &uptime_string);
        *str = replace_str(*str, "\%lm-uptime", uptime_string);
    }
    if (strstr(*str, "\%lh-uptime")){
        get_uptime(2, &uptime_string);
        *str = replace_str(*str, "\%lh-uptime", uptime_string);
    }
    if (strstr(*str, "\%ld-uptime")){
        get_uptime(3, &uptime_string);
        *str = replace_str(*str, "\%ld-uptime", uptime_string);
    }
    if (strstr(*str, "\%s-uptime")){
        get_uptime(4, &uptime_string);
        *str = replace_str(*str, "\%s-uptime", uptime_string);
    }
    if (strstr(*str, "\%distro")){
        get_distro(&distro_string);
        *str = replace_str(*str, "\%distro", distro_string);
    }
    if (strstr(*str, "\%wm")){
        get_wm(&wm_string);
        *str = replace_str(*str, "\%wm", wm_string);
    }
    if (strstr(*str, "\%terminal_type")){
        terminal_type = getenv("TERM");
        *str = replace_str(*str, "\%terminal_type", terminal_type);
    }
    if (strstr(*str, "\%resolution")){
        get_resolution(&resolution_string);
        *str = replace_str(*str, "\%resolution", resolution_string);
    }
    if (strstr(*str, "\%model")){
        get_model(&model_string);
        *str = replace_str(*str, "\%model", model_string);
    }
    if (strstr(*str, "\%shell")){
        get_shell(&shell_string);
        *str = replace_str(*str, "\%shell", shell_string);
    }
    if (strstr(*str, "\%pkg")){
        get_packages(&pkg_string);
        *str = replace_str(*str, "\%pkg", pkg_string);
    }
    if (strstr(*str, "\%ram_widget")){
        get_memory(&memory_string);
        *str = replace_str(*str, "\%ram_widget", memory_string);
    }
    if (strstr(*str, "\%gtk_theme")){
        get_gtk(&gtk_string, "gtk-theme-name", "gtk-theme");
        *str = replace_str(*str, "\%gtk_theme", gtk_string);
    }
    if (strstr(*str, "\%gtk_icons")){
        get_gtk(&gtk_string, "gtk-icon-theme-name", "icon-theme");
        *str = replace_str(*str, "\%gtk_icons", gtk_string);
    }
}


/* Parse the configuration file */
void read_configs(char *filename, char ***user_string, int *arr_len){
    FILE *fp;
    char *line = NULL;
    int index = 0;
    size_t len = 0;

    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not read configuration file!\n");
        safe_exit(EXIT_FAILURE);
    }

    int chars_read;
    while ((chars_read = getline(&line, &len, fp)) != -1) {
        /* Strip off any newlines */
        line[strcspn(line, "\n")] = 0;

        /* Add the line to our 2D array */
        (* user_string)[index] = malloc((strnlen(line, chars_read) + 1) * sizeof(char));
        memcpy((* user_string)[index], line, strnlen(line, chars_read) + 1);
        index++;
    }

    fclose(fp);
    if (line)
        free(line);
    
    *arr_len = index - 1;
}

char ** (* get_os_code(char **distro))(char *, char *, char **, int){
    /* Now, convert to lowercase. */
    for(int i = 0; i < strlen(*distro); i++){
        (*distro)[i] |= 32;
    }

    if(strstr(*distro, "aldos"))
        return aldos_logo;
    if(strstr(*distro, "alpine"))
        return alpine_logo;
    if(strstr(*distro, "antergos"))
        return antergos_logo;
    if(strstr(*distro, "archold"))
        return arch_old_logo;
    if(strstr(*distro, "arch"))
        return arch_logo;
    if(strstr(*distro, "artix"))
        return artix_logo;
    if(strstr(*distro, "blag"))
        return blag_logo;
    if(strstr(*distro, "blankon"))
        return blank_on_logo;

    if(strstr(*distro, "debian"))
        return debian_logo;
    
    if(strstr(*distro, "fedora"))
        return fedora_logo;
    
    if(strstr(*distro, "linux"))
        return tux;
    
    if(strstr(*distro, "mint"))
        return mint_logo;

    if(strstr(*distro, "ubuntu"))
        return ubuntu_logo;

    /* No ASCII art. */
    return NULL;

}

/* Figure  terminal_output how long strings should be to fit onscreen
   by doing strlen and ignoring the escape sequences. */
int count_special(char *str, int target_length){
    int i = 0;
    for(int pos = 0; pos < target_length; i++){
        if (str[i] == '\e' && str[i + 1] == '['){
            if (str[i + 4] == 'm')
                i += 5;
            else if (str[i + 5] == 'm')
                i += 6;
        }
        pos++;
    }
    return i;
}

int main (int argc, char *argv[]){
    /* Set up command-line options. */

    static struct option long_options[] = {
        {"aldos",      no_argument,  0, ALDOS},
        {"alpine",     no_argument,  0, ALPINE},
        {"antergos",   no_argument,  0, ANTERGOS},
        {"alpine",     no_argument,  0, ALPINE},
        {"archold",    no_argument,  0, ARCH_OLD},
        {"arch",       no_argument,  0, ARCH},
        {"artix",      no_argument,  0, ARTIX},
        {"blag",       no_argument,  0, BLAG},
        {"blankon",    no_argument,  0, BLANK_ON},
        {"debian",     no_argument,  0, DEBIAN},
        {"fedora",     no_argument,  0, FEDORA},
        {"mint",       no_argument,  0, MINT},
        {"ubuntu",     no_argument,  0, UBUNTU},
        {"linux",      no_argument,  0, LINUX},
        {"config",     required_argument, 0, 66},
        {0,           0,             0, 0 }
    };

    /* Get the window size */

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int len = 24;

    char **user_string;
    user_string = (char **)malloc(len * sizeof(char *));

    int opt= 0;
    int long_index = 0;
    char *opt_name = NULL;
    char **(* out_func)(char *, char *, char **, int) = NULL;
    char **(* tmp_art_lookup)(char *, char *, char **, int) = NULL;
 
    /* Evaluate the command-line arguments. */
    while ((opt = getopt_long_only(argc, argv,"", long_options, &long_index)) != -1) {
        if (opt == 66){
            /* Load configuration file */
            read_configs(argv[1], &user_string, &len);
        } else {
            /* Try to load artwork */
            asprintf(&opt_name, long_options[long_index].name);
            tmp_art_lookup = get_os_code(&opt_name);
            if(tmp_art_lookup)
                out_func = tmp_art_lookup;
        }
    }

    /* Deal with defaults */
    char *lead_color = YELLOW;
    char *second_color = BLUE;

    /* First, the configuration file */
    if(!*user_string){
        read_configs("/home/ben/github/slash/configurations/neofetch-style.txt", &user_string, &len);
    }

    /* Reverse the array for our printing function. */
    char *temp;
    int start = 0, end = len;
    while (start < end){
        temp = user_string[start];    
        user_string[start++] = user_string[end]; 
        user_string[end--] = temp; 
    }

    /* Replace special symbols */
    for(int i = 0; i <= len; i++){
        string_fill(&user_string[i]);
    }

    /* Secondly, get the OS code if the user didn't specify it. */
    char **terminal_output;
    if (!out_func){
        get_distro(&distro_string);
        terminal_output = get_os_code(&distro_string)(lead_color, second_color, user_string, len);
    } else {
        terminal_output = out_func(lead_color, second_color, user_string, len);
    }

    printf("\n");
    for(int i = 0; terminal_output[i] != 0; i++){
        /* Terminal commands don't count. */
        printf("%.*s%s%s\n", count_special( terminal_output[i], w.ws_col), terminal_output[i], DEFAULT, BG_DEFAULT);
    }

    /* Free up everything. */
    for(int i = 0; i < len; i++){
        free(user_string[i]);
    }

    for(int i = 0;  terminal_output[i] != 0; i++){
        free(terminal_output[i]);
    }
    free(user_string);
    safe_exit(0);
}