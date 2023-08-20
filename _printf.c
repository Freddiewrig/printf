#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _printf -  prints output according to a format
 * @format: character string
 * @...: urguments for format
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *str;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					str = va_arg(args, const char *);
					while (*str != '\0')
					{
						putchar(*str);
						str++;
						count++;
					}
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
