#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
int _printf(const char *format, ...);
int _print_char(va_list args, int *count);
int _print_string(va_list args, int *count);
int _print_percent(int *count);
int _print_integer(va_list args, int *count);
int _print_binary(va_list args, int *count);
int _handle_conversion(va_list args, char specifier, int *count);
void _print_unsign(va_list args, int *count);
void _print_octal(va_list args, int *count);
void _print_hex(va_list args, int *count, int uppercase);
#endif /* MAIN_H */
