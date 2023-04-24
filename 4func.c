#include "main.h"

/**
*get_width - gets the width of a string
*@s: the format string
*@params: the parameters struct
*@ptr_arr: the pointer
*Return: new pointer
*/

char *get_width(char *s, paramsvar *params, va_list ptr_arr)
{
	int d = 0;

	if (*S == '*')
	{
		d = va_arg(ptr_arr, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - ’O');
	}
	params->width = d;
	return (s);
}
