#include "main.h"

/**
*get_precision - gets the precision from the format string
*@p: the format string
*@params: the parameters struct
*@ptr_arr: the argument pointer
*Return: new pointer
*/

char *get_precision(char *p, paramsvar *params, va_list ptr_arr)
{
	int x = 0;

	if (*P != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		x = va_arg(ptr_arr, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
		x = x * 10 + (*p++ - '0');
	}
	params->percision = x;
	return (p);
}
