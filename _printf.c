#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _print_char - prints characters
 * @count: number of characters printed
 * @args: urguments
 * Return: count
 */
int _print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	putchar(c);
	(*count)++;
	return (*count);
}
/**
 * _print_integer - prints int
 * @count: printed int
 * @args: aguments
 * Return: count
 */
int _print_integer(va_list args, int *count)
{
	int num = va_arg(args, int);

	*count += printf("%d", num);
	return (*count);
}
/**
 * _print_string - prints a string
 * @count: character count
 * @args: arguments
 * Return: count
 */
int _print_string(va_list args, int *count)
{
	const char *str = va_arg(args, const char *);

	while (*str)
	{
		putchar(*str);
		str++;
		(*count)++;
	}
	return (*count);
}
/**
 * _print_percent - prints percent
 * @count: character count
 * Return: count
 */
int _print_percent(int *count)
{
	putchar('%');
	(*count)++;
	return (*count);
}
/**
 * _printf - prints output according to a format.
 * @format: character string
 * @...: urguments
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					_print_char(args, &count);
					break;
				case 's':
					_print_string(args, &count);
					break;
				case 'd':
				case 'i':
					_print_integer(args, &count);
					break;
				case '%':
					_print_percent(&count);
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
