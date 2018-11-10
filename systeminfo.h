void get_cpu_model(int length_mode, char **cpu_string);
void get_resolution(char **res);
void get_gpu(char **str);
void get_uptime(int length_mode, char **uptime_str);
void get_distro(char **distro_string);
void get_wm ();
void get_shell(char **shell_string);
void get_memory(char **mem_string);
void get_model(char **mem_string);
void get_packages(char **pkg_string);
void get_gtk (char **gtk_string, char *name, char *gsettings);
void get_wm_theme (char **theme_string, char **wm_string);

void rem_sub_str(char *str, const char *toRemove);
char *replace_str(const char *s, const char *oldW, const char *newW);