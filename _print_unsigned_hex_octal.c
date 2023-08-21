#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _print_unsign - prints unsigned int
 * @args: urguments
 * @count: number of int printed
 */
void _print_unsign(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	*count += printf("%u", num);
}
/**
 * _print_octal - prints octal
 * @args: urguments
 * @count: number of printed int
 */
void _print_octal(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);

	*count += printf("%o", num);
}
/**
 * _print_hex - prints hex
 * @args: urguments
 * @uppercase: uppercase
 * @count: number of printed int
 */
void _print_hex(va_list args, int *count, int uppercase)
{
	unsigned int num = va_arg(args, unsigned int);

	if (uppercase)
	{
		*count += printf("%X", num);
	}
	else
	{
		*count += printf("%x", num);
	}
}
