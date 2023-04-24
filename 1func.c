#include "main.h"

/**
*init_params - resrt structure fields and buffer
*@params: parameters struct
*@ptr_arr: argument pointer
*
*Return: void
*/

void init_params(paramsvar *params, va_list ptr_arr)
{
	params->unsign = 0;
	params->plus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;
	params->zero_flag = 0;
	params->minus_flag = 0;
	params->width = 0;
	params->precision = UINT_MAX;
	params->h_modifier = 0;
	params->l_modifier = 0;
	(void)ptr_arr;
}

/**
*_putchar - function that prints char c
*@c: a char to print
*Return: On success 1, On error -1 is returned
*/

int _putchar(int c)
{
	static int i;
	static char buf[OUTBUF_SIZE];

	if (BUF_FLUSH == C || OUTBUF_SIZE >= i)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
