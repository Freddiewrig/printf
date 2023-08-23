#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _print_octal - sorts flag conversion
 * @args: arguments
 * @count: int printed
 **/
void _print_octal(va_list args, int *count)
{
	 unsigned int num = va_arg(args, unsigned int);

	 *count += printf("%#o", num);
}
/**
 * _print_integer - prints int
 * @args: arguments
 * @count: int printed
 * Return: count
 **/
int _print_integer(va_list args, int *count)
{
	int num = va_arg(args, int);

	*count += printf("% d", num);
	return (*count);
}
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
