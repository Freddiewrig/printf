#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define BUFF_SIZE 1024
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *str;
	int count = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					print_buffer(buffer, &buff_ind);
					putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					{
						print_buffer(buffer, &buff_ind);
						str = va_arg(args, const char *);

						while (*str)
						{
							putchar(*str);
							str++;
							count++;
						}
					}
					break;
				case '%':
					print_buffer(buffer, &buff_ind);
					putchar('%');
					count++;
					break;
				default:
					print_buffer(buffer, &buff_ind);
					putchar('%');
					putchar(*format);
					count += 2;
					break;
			}
		}
		else
		{
			buffer[buff_ind++] = *format;
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			count++;
		}
		format++;
	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (count);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
