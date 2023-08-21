#include "main.h"
#include <stdio.h>
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
