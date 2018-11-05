#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Code courtesy rofl on StackOverflow:
// https://codereview.stackexchange.com/questions/67055/fastest-way-of-removing-a-substring-from-a-string
void rem_sub_str(char *str, const char *toRemove) {
    if (NULL == (str = strstr(str, toRemove))){
        // No match, no need to do anything
        return;
    }

    // str points to toRemove in str now.
    const size_t remLen = strlen(toRemove);
    char *copyEnd;
    char *copyFrom = str + remLen;
    while (NULL != (copyEnd = strstr(copyFrom, toRemove))){  
        memmove(str, copyFrom, copyEnd - copyFrom);
        str += copyEnd - copyFrom;
        copyFrom = copyEnd + remLen;
    }
    memmove(str, copyFrom, 1 + strlen(copyFrom));
}

// Quick and easy, replace this with something better.
// Proof of concept.
char *replace_str(const char *s, const char *oldW, 
                                 const char *newW){
    char *result; 
    int i, cnt = 0; 
    int newWlen = strlen(newW); 
    int oldWlen = strlen(oldW); 
  
    // Counting the number of times the old word 
    // occur in the string 
    for (i = 0; s[i] != '\0'; i++) { 
        if (strstr(&s[i], oldW) == &s[i]){ 
            cnt++; 
  
            // Jumping to index after the old word. 
            i += oldWlen - 1; 
        }
    }
  
    // Making new string of enough length 
    result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1); 
  
    i = 0; 
    while (*s){ 
        // compare the substring with the result 
        if (strstr(s, oldW) == s){ 
            strcpy(&result[i], newW); 
            i += newWlen; 
            s += oldWlen; 
        } 
        else
            result[i++] = *s++; 
    } 
  
    result[i] = '\0'; 
    return result; 
}

// 0 - full string
// 1 - Remove TM, R, C.
// 2 - Drop manufacturer name altogether.
void get_cpu_model(int length_mode, char **cpu_string){
   FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
   char *arg = 0;
   char *token;
   size_t size = 0;

    getdelim(&arg, &size, 0, cpuinfo);

    token = strtok(arg, "\n");
    while (token != NULL && !strstr(token, "model name")){
        token = strtok(NULL, "\n");
    }

    // Now, just get the CPU model.
    char *cpu_name = strtok(token, ":");

    // Skip over the lead part
    cpu_name = strtok(NULL, ":");
    *cpu_name++;

    strcpy(*cpu_string, cpu_name);

    rem_sub_str(*cpu_string, "CPU ");
    if(length_mode > 0){
        rem_sub_str(*cpu_string, "(R)");
        rem_sub_str(*cpu_string, "(TM)");
        rem_sub_str(*cpu_string, "(C)");
    }
    if(length_mode > 1){
       rem_sub_str(*cpu_string, " Core");
       rem_sub_str(*cpu_string, "Intel ");
    }

    free(arg);
    fclose(cpuinfo);
}

void get_resolution(char **res){
    char tmp[32];
    char* token;
    int num_iterations = 0;
    FILE *fp = popen("xrandr | fgrep '*'", "r");

    if (fp == NULL) {
        printf("Failed to run xrandr or fgrep to get resolution.\n" );
        exit(1);
    }

    while (fgets(tmp, sizeof(tmp) - 1, fp) != NULL) {
        if (num_iterations++)
            strcat(*res, ", ");

        token = strtok(tmp, " ");
        strcat(*res, token);

        // Now, for hz
        token = strtok(NULL, " ");
    }
}

void get_gpu(char **str){
    /* Open the command for reading. */
    FILE *fp = popen("lspci -mm", "r");
    if (fp == NULL) {
        printf("Failed to run lspci to get GPU model\n" );
        exit(1);
    }

    char tmp[128], manufacturer[128];

    /* Read the output a line at a time - output it. */
    while (fgets(tmp, sizeof(tmp) - 1, fp) != NULL) {
        if(strstr(tmp, "VGA compatible controller")){
            /* Since we're using LSPCI, we know the lead format is XX:YY.Z
               We don't need it, so strip it. */
            /* AA:BB:C */
            char *token = strtok(tmp, "\"");
            
            /* VGA compatible controller */
            token = strtok(NULL, "\"");

            /* Whitespace */
            token = strtok(NULL, "\"");

            /* Company */
            token = strtok(NULL, "\"");

            if (strstr(token, "Intel"))
                strcpy(manufacturer, "Intel");
            else if (strstr(token, "AMD") || strstr(token, "ATI")
                     || strstr(token, "ATi"))
                strcpy(manufacturer, "AMD/ATi");
            else if (strstr(token, "NVIDIA")){
                strcpy(manufacturer, "NVIDIA");
            }
            
            /* Whitespace */
            token = strtok(NULL, "\"");

            /* Model */
            token = strtok(NULL, "\"");

            /* Remove everything before the brackets. */
            if (strstr(token, "[")){
                while(*token != '['){
                    token++;
                }
                token++;
            }

            /* Remove end */
            token[strcspn(token, "]")] = 0;

            sprintf(*str, "%s %s", manufacturer, token);
            
            break;
        }
    }

    /* Strip off any newlines */
    (*str)[strcspn(*str, "\n")] = 0;
    
    /* close */
    pclose(fp);
}

// 0 - full string (AA days, BB hours, CC mins, DD secs)
// 1 - full string, no seconds  (AA days, BB hours, CC mins)
// 2 - full string, no seconds or minutes  (AA days, BB hours)
// 3 - full string, hours only  (BB hours)
// 4 - short mode (AAd BBh CCm)
void get_uptime(int length_mode, char **uptime_str){
   FILE *cpuinfo = fopen("/proc/uptime", "rb");
   char *arg = 0;
   char *ptr;
   size_t size = 0;

    if (getdelim(&arg, &size, 0, cpuinfo) ==  -1){
        printf("Could not get uptime.");
        return;
    }
    long ret = strtol(arg, &ptr, 10);
    int days = ret / (24 * 3600);
    ret -= days * (24 * 3600);
    int hours = ret / 3600;
    ret -= hours * 3600;
    int min = ret / 60;
    ret -= min * 60;

    if (!length_mode)
        sprintf(*uptime_str, "%d days, %d hours, %d mins, %ld secs", days, hours, min, ret);
    else if (length_mode == 1)
        sprintf(*uptime_str, "%d days, %d hours, %d mins", days, hours, min);
    else if (length_mode == 2)
        sprintf(*uptime_str, "%d days, %d hours", days, hours);
    else if (length_mode == 3)
        sprintf(*uptime_str, "%d hours", hours);
    else if (length_mode == 4)
        sprintf(*uptime_str, "%dd %dh %dm", days, hours, min);
}

void get_distro(char **distro_string){
    FILE *fp = popen("lsb_release -d", "r");
    if (fp == NULL) {
        printf("Failed to run lsb_release to get distribution\n" );
        return;
    }

    char tmp[128];
    if(fgets(tmp, sizeof(tmp) - 1, fp) == NULL){
        printf("Could not read information from lsb_release");
        return;
    }
    char *token = strtok(tmp, "\t");
    token = strtok(NULL, "\t");

    /* Strip off any newlines */
    token[strcspn(token, "\n")] = 0;

    strcpy(*distro_string, token);
}

void get_shell(char **shell_string){
    strcpy(*shell_string, getenv("SHELL"));
}

void get_wm (char **wm_string){
    /* Ideally, call GDMSESSION to get the wm. */
    strcpy(*wm_string, getenv("GDMSESSION"));

    /* Fallback: seach through all processes. */
    if(!strlen(*wm_string)){
        // Not as expensive as Screenfetch's pgrep, but not cheap, either.
        char *supported_wm[] = {"fluxbox", "openbox", "blackbox",
                                "xfwm4", "metacity", "kwin",
                                "twin", "icewm", "pekwm", 
                                "flwm", "flwm_topside", "fvwm",
                                "dwm", "awesome", "wmaker",
                                "stumpwm", "musca", "xmonad.*",
                                "i3", "ratpoison", "scrotwm",
                                "spectrwm", "wmfs", "wmii",
                                "beryl", "subtle", "e16",
                                "enlightenment", "sawfish", "emerald",
                                "monsterwm", "dminiwm", "compiz",
                                "Finder", "herbstluftwm", "howm",
                                "notion", "bspwm", "cinnamon",
                                "2bwm", "echinus", "swm",
                                "budgie-wm", "dtwm", "9wm",
                                "chromeos-wm", "deepin-wm", "sway",
                                "mwm" };

        FILE *fp = popen("ps aux", "r");
        char *lookup = malloc(128);

        while (fgets(lookup, sizeof(lookup) - 1, fp) != NULL) {
            for(int i = 0; i < 49; i++){
                if(strstr(lookup, supported_wm[i]) != NULL){
                    strcpy(*wm_string, supported_wm[i]);
                    return;
                }
            }
        }
        strcpy(*wm_string, "Unknown");
    }
}

void get_memory(char **mem_string){
    FILE* fp = fopen("/proc/meminfo", "r");

    char tmp[128];
    char *token, *ptr;
    size_t total_mem = 0,
           free_mem = 0,
           buffers = 0,
           cached = 0;

    while (fgets(tmp, sizeof(tmp) - 1, fp) != NULL &&
           !(total_mem && free_mem && buffers && cached)){
        /* Title */
        token = strtok(tmp, " ");

        /* Value */
        if (!strcmp(token, "MemTotal:")){
            token = strtok(NULL, " ");
            total_mem = strtol(token, &ptr, 10);
        }else if (!strcmp(token, "MemAvailable:")){
            token = strtok(NULL, " ");
            free_mem = strtol(token, &ptr, 10);
        }else if (!strcmp(token, "Buffers:")){
            token = strtok(NULL, " ");
            buffers = strtol(token, &ptr, 10);
        }else if (!strcmp(token, "Cached:")){
            token = strtok(NULL, " ");
            cached = strtol(token, &ptr, 10);
        }
    }
    sprintf(*mem_string, "%zi MiB / %zi MiB",
            (total_mem - free_mem - buffers) / 1024, total_mem / 1024);
}

void get_model(char **mem_string){
    char tmp[128];

    FILE* fp;

    /* Try to get this info, could be stored in multiple places. */
    if ((fp = fopen("/sys/devices/virtual/dmi/id/product_name", "r")) != NULL){}
    else if (((fp = fopen("/sys/firmware/devicetree/base/model", "r")) != NULL)){}
    else if (((fp = fopen("tmp/sysinfo/model", "r")) != NULL)){}

    if(fp == NULL){
       strcpy(*mem_string, "Unknown");
       return;
    }

    
    fgets(tmp, 127, fp);

    /* Strip off any newlines */
    tmp[strcspn(tmp, "\n")] = 0;

    strcpy(*mem_string, tmp);   
}

void get_packages(char **pkg_string){
    FILE* fp;
    char tmp[128];

    /* Try to get this info, could be stored in multiple places. */
    char *pm;
    if ((fp = popen("pacman -Qq --color never | wc -l", "r")) != NULL)
        pm = "pacman";
    else if (((fp = popen("dpkg-query -f '.\n' -W | wc -l", "r")) != NULL))
        pm = "dpkg";
    else if (((fp = popen("pm -qa | wc -l", "r")) != NULL))
        pm = "rpm";
    else if (((fp = popen("xbps-query -l | wc -l", "r")) != NULL))
        pm = "xbps";
    else if (((fp = popen("apk info | wc -l", "r")) != NULL))
        pm = "apk";
    else if (((fp = popen("opkg list-installed | wc -l", "r")) != NULL))
        pm = "opkg";
    else if (((fp = popen("pacman-g2 | wc -l", "r")) != NULL))
        pm = "pacman-g2";

    if(fp == NULL){
       strcpy(*pkg_string, "Unknown");
       return;
    }

    fgets(tmp, 127, fp);
    tmp[strcspn(tmp, "\n")] = 0;

    sprintf(*pkg_string, "%s (%s)", tmp, pm);
}