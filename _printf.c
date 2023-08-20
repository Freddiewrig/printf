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
	int i = 0;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					printf("%s", va_arg(args, char *));
						count++;
					break;
				case '%':
					putchar('%');
					count++;
					break;
				default:
					putchar('%');
					putchar(format[i]);
					count += 2;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
