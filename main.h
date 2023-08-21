#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int _print_char(va_list args, int *count);
int _print_string(va_list args, int *count);
int _print_percent(int *count);
#endif /* MAIN_H */
