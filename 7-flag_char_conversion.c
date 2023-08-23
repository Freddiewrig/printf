#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * handle_flags - gives out flags
 * @char specifier: points out to a char
 * @current_flag: gives out flag
 **/
void handle_flags(char specifier, char *current_flag)
{
	char flags[3] = {'+', ' ', '#'};

	for (int i = 0; i < 3; i++)
	{
		if (specifier == flags[i])
		{
			*current_flag = flags[i];
			break;
		}
	}
}
