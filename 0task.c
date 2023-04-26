#include "main.h"

void prnt_buff(char buffer[], int *indx_buf);

/**
 * _printf - function that prints any given format
 * @format: a string
 * Return: Printed charchters
*/
int _printf(const char *format, ...)
{
	int ittr, printed = 0, total_chars = 0;
	int flags, width, precision, size, indx_buf = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (ittr = 0; format && format[ittr] != '\0'; ittr++)
	{
		if (format[ittr] != '%')
		{
			buffer[indx_buf++] = format[ittr];
			if (indx_buf == BUFF_SIZE)
				prnt_buff(buffer, &indx_buf);
			total_chars++;
		}
		else
		{
			prnt_buff(buffer, &indx_buf);
			flags = get_flags(format, &ittr);
			width = get_width(format, &ittr, list);
			precision = get_precision(format, &ittr, list);
			size = get_size(format, &ittr);
			++ittr;
			printed = handle_print(format, &ittr, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			total_chars += printed;
		}
	}

	prnt_buff(buffer, &indx_buf);

	va_end(list);

	return (total_chars);
}

/**
 * prnt_buff - Prints the buffer contents
 * @buffer: Array of chars
 * @indx_buf: Index that represents the length
*/
void prnt_buff(char buffer[], int *indx_buf)
{
	if (*indx_buf > 0)
		write(1, &buffer[0], *indx_buf);

	*indx_buf = 0;
}
