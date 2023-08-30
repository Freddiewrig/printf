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
 * _handle_conversion - handles according to a format.
 * @specifier: character string
 * @count: character printed
 * @args: arguments
 * Return: 0 (success)
 */
int _handle_conversion(va_list args, char specifier, int *count)
{
	switch (specifier)
	{
		case 'c':
			_print_char(args, count);
			break;
		case 's':
			_print_string(args, count);
			break;
		case 'd':
		case 'i':
			_print_integer(args, count);
			break;
		case 'u':
			_print_unsign(args, count);
			break;
		case 'o':
			_print_octal(args, count);
			break;
		case 'x':
			_print_hex(args, count, 0);
			break;
		case 'X':
			_print_hex(args, count, 1);
			break;
		case 'b':
			_print_binary(args, count);
			break;
		case '%':
			_print_percent(count);
			break;
		case 'S':
			_print_string_special(args, count);
			break;
		default:
			putchar('%');
			putchar(specifier);
			count += 2;
			break;
	}
	return (0);
}
/**
 * _printf - prints characters according to a format
 * @format: character string
 * @...: functions
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
			_handle_conversion(args, *format, &count);
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
