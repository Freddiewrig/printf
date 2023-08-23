#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _flag_conversion - sorts flag conversion
 * @args: arguments
 * @count: int printed
 **/
void _flag_conversion(va_list args, int *count)
{
	 unsigned int num = va_arg(args, unsigned int);

	 *count += printf("%#o", num);
	 *count += printf("% d", num);
	 *count += printf("%+d", num);
}
