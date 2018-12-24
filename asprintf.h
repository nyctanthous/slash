#ifndef _vscprintf
int _vscprintf_so(const char * format, va_list pargs);
#endif

#ifndef vasprintf
int vasprintf(char **strp, const char *fmt, va_list ap);
#endif

#ifndef asprintf
int asprintf(char *strp[], const char *fmt, ...);
#endif