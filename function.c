#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - produces output according to a format
 * @format: string of characters
 * @...: urguments of format
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int num;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'd':
				case 'i':
					num = va_arg(args, int);
					putchar('0' + num);
					count++;
					break;
				default:
					putchar(*format);
					count++;
					break;
			}
		}
		else
		{
			putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
