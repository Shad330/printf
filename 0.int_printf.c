#include "main.h"

/**
* int _printf - function that prints outputs according to given format
*@format: a string
*
*Return: int
*/

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;
	const char *p = format;

	while (*p != '\0')
	{
		if (*p == '%')
		{
		p++;

		switch (*p)
		{
			case 'c':
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				count++;
				break;
			}
			case 's':
			{
				char *s = va_arg(args, char *)

				while (*s != '\0')
				{
				write(1, s, 1);
				s++;
				count++;
				}
				break;
			}
			case '%':
			{
				write(1, "%", 1);
				count++;
				break;
			}
			default:
			{
				break
			}
		}
		}
		else
		{
			write(1, p, 1);
			count++;
		}
		p++;
}
	va_end(args);
	return (count);
}
