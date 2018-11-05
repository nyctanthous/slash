#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <getopt.h>
#include "systeminfo.h"
#include "definitions.h"


#define put(index, char_array) (index >= 0? (char_array[index--]) : "")

// Now, some globals we'll *probably* need to use.
char hostname[HOST_NAME_MAX];
char *user;
char *uptime;
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
char *distro;
char *terminal_type;
struct utsname unameData;

void aldos_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s                            %s\n", c1, put(num_info_lines, info));
    printf("%s           # ## #           %s\n", c1, put(num_info_lines, info));
    printf("%s        # ######## #        %s\n", c1, put(num_info_lines, info));
    printf("%s      # ### ######## #      %s\n", c1, put(num_info_lines, info));
    printf("%s     # #### ######### #     %s\n", c1, put(num_info_lines, info));
    printf("%s   # #### # # # # #### #    %s\n", c1, put(num_info_lines, info));
    printf("%s  # ##### #       ##### #   %s\n", c1, put(num_info_lines, info));
    printf("%s   # ###### ##### #### #    %s\n", c1, put(num_info_lines, info));
    printf("%s    # ############### #     %s\n", c1, put(num_info_lines, info));
    printf("%s                            %s\n", c1, put(num_info_lines, info));
    printf("%s         _ ___   ___  ___   %s\n", c2, put(num_info_lines, info));
    printf("%s    __ _| |   \\ / _ \\/ __|  %s\n", c2, put(num_info_lines, info));
    printf("%s   / _' | | |) | (_) \\__ \\  %s\n", c2, put(num_info_lines, info));
    printf("%s   \\__,_|_|___/ \\___/|___/  %s\n", c2, put(num_info_lines, info));
    printf("%s                            %s\n", c1, put(num_info_lines, info));
    printf("%s                            %s\n", c1, put(num_info_lines, info));
}

void antergos_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s              `.-/::/-``                  %s\n", c1, put(num_info_lines, info));
    printf("%s             .-/osssssssso/.              %s\n",    c1, put(num_info_lines, info));
    printf("%s            :osyysssssssyyys+-            %s\n",    c1, put(num_info_lines, info));
    printf("%s         `.+yyyysssssssssyyyyy+.          %s\n",   c1, put(num_info_lines, info));
    printf("%s        `/syyyyyssssssssssyyyyys-`        %s\n",  c1, put(num_info_lines, info));
    printf("%s       `/yhyyyyysss%s++%sssosyyyyhhy/`        %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s      .ohhhyyyys%so++/+o%sso%s+%ssyy%s+%sshhhho.      %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s     .shhhhys%soo++//+%ssss%s+++%syyy%s+s%shhhhs.     %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s    -yhhhhs%s+++++++o%sssso%s+++%syyy%ss+o%shhddy:    %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s   -yddhhy%so+++++o%ssyyss%s++++%syyy%syooy%shdddy-   %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s  .yddddhs%so++o%ssyyyyys%s+++++%syyhh%ssos%shddddy`  %s\n",  c1, c2, c1, c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s `odddddhyosyhyyyyyy%s++++++%syhhhyosddddddo  %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s .dmdddddhhhhhhhyyyo%s+++++%sshhhhhohddddmmh. %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s ddmmdddddhhhhhhhso%s++++++%syhhhhhhdddddmmdy %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s dmmmdddddddhhhyso%s++++++%sshhhhhddddddmmmmh %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s -dmmmdddddddhhys%so++++o%sshhhhdddddddmmmmd- %s\n",  c1, c2, c1, put(num_info_lines, info));
    printf("%s .smmmmddddddddhhhhhhhhhdddddddddmmmms.   %s\n", c1, put(num_info_lines, info));
    printf("%s    `+ydmmmdddddddddddddddddddmmmmdy/.    %s\n", c1, put(num_info_lines, info));
    printf("%s       `.:+ooyyddddddddddddyyso+:.`       %s\n", c1, put(num_info_lines, info));
}

void archold_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s              __                    %s\n", c1, put(num_info_lines, info));
    printf("%s         _=(SDGJT=_                 %s\n", c1, put(num_info_lines, info));
    printf("%s       _GTDJHGGFCVS)                %s\n", c1, put(num_info_lines, info));
    printf("%s      ,GTDJGGDTDFBGX0               %s\n", c1, put(num_info_lines, info));
    printf("%s     JDJDIJHRORVFSBSVL%s-=+=,_        %s\n", c1, c2, put(num_info_lines, info));
    printf("%s    IJFDUFHJNXIXCDXDSV,%s  \\\"DEBL     %s\n", c1, c2, put(num_info_lines, info));
    printf("%s   [LKDSDJTDU=OUSCSBFLD.%s   '?ZWX,   %s\n", c1, c2, put(num_info_lines, info));
    printf("%s  ,LMDSDSWH'     \\`DCBOSI%s     DRDS],%s\n", c1, c2, put(num_info_lines, info));
    printf("%s  SDDFDFH'         !YEWD,%s   )HDROD  %s\n", c1, c2, put(num_info_lines, info));
    printf("%s !KMDOCG            &GSU|%s\\_GFHRGO\'  %s\n", c1, c2, put(num_info_lines, info));
    printf("%s HKLSGP'%s           __%s\\TKM0%s\\GHRBV)'  %s\n", c1, c2, c1, c2, put(num_info_lines, info));
    printf("%sJSNRVW'%s       __+MNAEC%s\\IOI,%s\\BN'     %s\n", c1, c2, c1, c2, put(num_info_lines, info));
    printf("%sHELK['%s    __,=OFFXCBGHC%s\\FD)         %s\n", c1, c2, c1, put(num_info_lines, info));
    printf("%s?KGHE %s\\_-#DASDFLSV='%s    'EF         %s\n", c1, c2, c1, put(num_info_lines, info));
    printf("%s'EHTI                    !H         %s\n", c1, put(num_info_lines, info));
    printf("%s \\`0F'                    '!        %s\n", c1, put(num_info_lines, info));
    printf("%s                                    %s\n", c1, put(num_info_lines, info));
    printf("%s                                  %s\n", c1, put(num_info_lines, info));
}

void arch_logo(char *c1, char *c2, char **info, int num_info_lines){
    printf("%s                   -`                  %s\n", c1, put(num_info_lines, info));
    printf("%s                  .o+`                 %s\n", c1, put(num_info_lines, info));
    printf("%s                 `ooo/                 %s\n", c1, put(num_info_lines, info));
    printf("%s                `+oooo:                %s\n", c1, put(num_info_lines, info));
    printf("%s               `+oooooo:               %s\n", c1, put(num_info_lines, info));
    printf("%s               -+oooooo+:              %s\n", c1, put(num_info_lines, info));
    printf("%s             `/:-:++oooo+:             %s\n", c1, put(num_info_lines, info));
    printf("%s            `/++++/+++++++:            %s\n", c1, put(num_info_lines, info));
    printf("%s           `/++++++++++++++:           %s\n", c1, put(num_info_lines, info));
    printf("%s          `/+++o%soooooooo%soooo/`         %s\n", c1, c2, c1, put(num_info_lines, info));
    printf("%s         %s./%sooosssso++osssssso%s+`        %s\n", c2, c1, c2, c1, put(num_info_lines, info));
    printf("%s        .oossssso-````/ossssss+`       %s\n", c2, put(num_info_lines, info));
    printf("%s       -osssssso.      :ssssssso.      %s\n", c2, put(num_info_lines, info));
    printf("%s      :osssssss/        osssso+++.     %s\n", c2, put(num_info_lines, info));
    printf("%s     /ossssssss/        +ssssooo/-     %s\n", c2, put(num_info_lines, info));
    printf("%s   `/ossssso+/:-        -:/+osssso+-   %s\n", c2, put(num_info_lines, info));
    printf("%s  `+sso+:-`                 `.-/+oso:  %s\n", c2, put(num_info_lines, info));
    printf("%s `++:.                           `-/+/ %s\n", c2, put(num_info_lines, info));
    printf("%s .`                                 `/ %s\n", c2, put(num_info_lines, info));
}

void string_replacer(char **str, char *symbol, char *color){
    if (strstr(*str, symbol))
        *str = replace_str(*str, symbol, color);
}

void add_to_list(char ***list, int *arr_len, int *index, char* str){
    // First, add foreground color escape sequences.
    string_replacer(&str, "?b", BLUE);
    string_replacer(&str, "?r", RED);
    string_replacer(&str, "?l", BLACK);
    string_replacer(&str, "?q", DARK_GRAY);
    string_replacer(&str, "?w", WHITE);
    string_replacer(&str, "?c", CYAN);
    string_replacer(&str, "?y", YELLOW);
    string_replacer(&str, "?m", MAGENTA);
    string_replacer(&str, "?d", DEFAULT);

    // Add light foreground color escape sequences.
    string_replacer(&str, "$q", LIGHT_GRAY);
    string_replacer(&str, "$b", LIGHT_BLUE);
    string_replacer(&str, "$r", LIGHT_RED);
    string_replacer(&str, "$c", LIGHT_CYAN);
    string_replacer(&str, "$y", LIGHT_YELLOW);
    string_replacer(&str, "$m", LIGHT_MAGENTA);

    // Then, add background color escape sequences.
    string_replacer(&str, "/b", BG_BLUE);
    string_replacer(&str, "/g", BG_GREEN);
    string_replacer(&str, "/r", BG_RED);
    string_replacer(&str, "/l", BG_BLACK);
    string_replacer(&str, "/c", BG_CYAN);
    string_replacer(&str, "/y", BG_YELLOW);
    string_replacer(&str, "/m", BG_MAGENTA);
    string_replacer(&str, "/w", BG_WHITE);
    string_replacer(&str, "/q", BG_DARK_GRAY);
    string_replacer(&str, "/d", BG_DEFAULT);

    // Add light background color escape sequences.
    string_replacer(&str, "\\b", BG_LIGHT_BLUE);
    string_replacer(&str, "\\g", BG_LIGHT_GREEN);
    string_replacer(&str, "\\r", BG_LIGHT_RED);
    string_replacer(&str, "\\c", BG_LIGHT_CYAN);
    string_replacer(&str, "\\y", BG_LIGHT_YELLOW);
    string_replacer(&str, "\\m", BG_LIGHT_MAGENTA);
    string_replacer(&str, "\\q", BG_LIGHT_GRAY);

    if (strstr(str, "\%host")){
        gethostname(hostname, HOST_NAME_MAX);
        str = replace_str(str, "\%host", hostname);
    }
    if (strstr(str, "\%user")){
        user = getlogin();
        str = replace_str(str, "\%user", user);
    }
    if (strstr(str, "\%kernel")){
        uname(&unameData);
        str = replace_str(str, "\%kernel", unameData.release);
    }
    if (strstr(str, "\%gpu")){
        get_gpu(&gpu_string);
        str = replace_str(str, "\%gpu", gpu_string);
    }
    if (strstr(str, "\%l-cpu")){
        get_cpu_model(0, &cpu_string);
        str = replace_str(str, "\%l-cpu", cpu_string);
    }
    if (strstr(str, "\%cpu")){
        get_cpu_model(1, &cpu_string);
        str = replace_str(str, "\%cpu", cpu_string);
    }
    if (strstr(str, "\%s-cpu")){
        get_cpu_model(2, &cpu_string);
        str = replace_str(str, "\%s-cpu", cpu_string);
    }
    if (strstr(str, "\%ls-uptime")){
        get_uptime(0, &uptime_string);
        str = replace_str(str, "\%ls-uptime", uptime_string);
    }
    if (strstr(str, "\%lm-uptime")){
        get_uptime(1, &uptime_string);
        str = replace_str(str, "\%lm-uptime", uptime_string);
    }
    if (strstr(str, "\%lh-uptime")){
        get_uptime(2, &uptime_string);
        str = replace_str(str, "\%lh-uptime", uptime_string);
    }
    if (strstr(str, "\%ld-uptime")){
        get_uptime(3, &uptime_string);
        str = replace_str(str, "\%ld-uptime", uptime_string);
    }
    if (strstr(str, "\%s-uptime")){
        get_uptime(4, &uptime_string);
        str = replace_str(str, "\%s-uptime", uptime_string);
    }
    if (strstr(str, "\%distro")){
        get_distro(&distro_string);
        str = replace_str(str, "\%distro", distro_string);
    }
    if (strstr(str, "\%wm")){
        get_wm(&wm_string);
        str = replace_str(str, "\%wm", wm_string);
    }
    if (strstr(str, "\%terminal_type")){
        terminal_type = getenv("TERM");
        str = replace_str(str, "\%terminal_type", terminal_type);
    }
    if (strstr(str, "\%resolution")){
        get_resolution(&resolution_string);
        str = replace_str(str, "\%resolution", resolution_string);
    }
    if (strstr(str, "\%model")){
        get_model(&model_string);
        str = replace_str(str, "\%model", model_string);
    }
    if (strstr(str, "\%shell")){
        get_shell(&shell_string);
        str = replace_str(str, "\%shell", shell_string);
    }
    if (strstr(str, "\%pkg")){
        get_packages(&pkg_string);
        str = replace_str(str, "\%pkg", pkg_string);
    }
    if (strstr(str, "\%ram_widget")){
        get_memory(&memory_string);
        str = replace_str(str, "\%ram_widget", memory_string);
    }
    
    if (*arr_len > *index){
        (*list)[*index] = (char*)malloc(180 * sizeof(char));
        strncpy((*list)[*index], str, 179);
        (*index)++;
    }
    else
        // Resizing code
        printf("Resize Here");
}


void read_configs(char *filename, char ***user_string, int *arr_len){
    FILE *fp;
    char *line = NULL;
    int index = 0;
    size_t len = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while (getline(&line, &len, fp) != -1) {
        // Strip off any newlines
        line[strcspn(line, "\n")] = 0;
        add_to_list(user_string, arr_len, &index, line);
    }

    fclose(fp);
    if (line)
        free(line);
    
    *arr_len = index - 1;
}

int main (int argc, char *argv[]){
    gpu_string = malloc(128);
    cpu_string = malloc(128);
    wm_string = malloc(64);
    distro_string = malloc(64);
    resolution_string = malloc(128);
    uptime_string = malloc(128);
    shell_string = malloc(128);
    memory_string = malloc(128);
    model_string = malloc(256);
    pkg_string = malloc(256);

    static struct option long_options[] = {
        {"aldos",      no_argument,  0, ALDOS },
        {"antergos",   no_argument,  0, ANTERGOS },
        {"alpine",     no_argument,  0, ALPINE },
        {"archold",    no_argument,  0, ARCHOLD },
        {"arch",       no_argument,  0, ARCH },
        {0,           0,             0, 0 }
    };

    static void (*logo_lookup[13]) (char *, char *, char **, int);
    logo_lookup[ALDOS]    = &aldos_logo;
    logo_lookup[ANTERGOS] = &antergos_logo;
    logo_lookup[ARCHOLD]  = &archold_logo;
    logo_lookup[ARCH]     = &arch_logo;

    int opt= 0;
    int long_index = 0;

    opt = getopt_long_only(argc, argv,"", long_options, &long_index);
    if (opt < 0){
        printf("Please add a command line argument for the OS.\n");
        return -1;
    }

    /* Start with 20 options, resize if larger. */
    int len = 24;
    char *lead_color = YELLOW;
    char *second_color = BLUE;

    char **user_string;
    user_string = malloc(len * sizeof(char *));
    read_configs("configurations/neofetch-style.txt", &user_string, &len);

    /* Reverse the array for our printing function. */
    char *temp;
    int start = 0, end = len;
    while (start < end){
        temp = user_string[start];    
        user_string[start++] = user_string[end]; 
        user_string[end--] = temp; 
    }

    /* Actually print the logo and info */
    logo_lookup[opt](lead_color, second_color, user_string, len);
    printf("%s%s\n", DEFAULT, BG_DEFAULT);

    /* Free up everything. */
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

    // MAY NOT BE FREE'D CORRECTLY
    free(user_string);
}