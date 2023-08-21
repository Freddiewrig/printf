#include "main.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _print_binary - unsigned int argument is converted to binary
 * @args: arguments
 * @count: printed characters
 * Return: count
 */
int _print_binary(va_list args, int *count)
{       
        unsigned int num = va_arg(args, unsigned int);
        int binary[32];
        int index = 0;
        
        while (num > 0)
        {       
                binary[index] = num % 2;
                num /= 2;
		index++;
	}
	if (index == 0)
	{
		putchar('0');
		(*count)++;
	}
	else
	{
		for (int i = index - 1; i >= 0; i--)
		{
			putchar('0' + binary[i]);
			(*count)++;
		}
	}
	return (*count);
}
