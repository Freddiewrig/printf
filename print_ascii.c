#include <stdio.h>
#include "main.h"
/**
 * _print_string_special - prints a string with non-printable
 * characters as specified.
 * @args: arguments
 * @count: character count
 * Return: count
 */
int _print_string_special(va_list args, int *count)
{
	const char *str = va_arg(args, const char *);

	while (*str)
	{
		if (*str >= 0 && *str < 32)
		{
			putchar('\\');
			putchar('x');
			putchar((*str / 16) + '0');
			putchar((*str % 16 < 10) ? (*str % 16 + '0') :
					(*str % 16 - 10 + 'A'));
			(*count) += 4;
		}
		else if (*str >= 127)
		{
			putchar('\\');
			putchar('x');
			putchar((*str / 16) + '0');
			putchar((*str % 16 < 10) ? (*str % 16 + '0') :
					(*str % 16 - 10 + 'A'));
			(*count) += 4;
		}
		else
		{
			putchar(*str);
			(*count)++;
		}
		str++;
	}
	return (*count);
}
