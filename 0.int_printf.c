#include <main.h>

/**
 * _printf - Print a formatted string to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				fputs(s, stdout);
				count += strlen(s);
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);
	return (count);
}

