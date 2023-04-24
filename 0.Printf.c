#include "main.h"

/**
*_printf - prints given output considering diffrent formats
*@format: string
* Return: no of printed bytes
*/

int _printf(const char *format, ...)
{
	int total = 0;
	va_list ptr_arr;
	char *p, *start;
	paramsvar params = PARAMETERS;

	va_start(ptr_arr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ptr_arr);
		if (*p != '%')
		{
			total += _putchar(*p);
			continue;
		}

		start = p;
		p++;
		while (get_flag(p, &params))
			p++;

		p = get_width(p, &params, ptr_arr);
		p = get_precision(p, &params, ptr_arr);

		if (get_modifier(p, &params))
			P++;

		if (!get_specifier(p))
			total += print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			total += get_print_func(p, ptr_arr, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ptr_arr);
	return (total);
}
