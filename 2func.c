#include "main.h"

/**
*get_specifier - finds the format func
*@s: the format string
*Return: the number of bytes printed
*/

int (*get_specifier(char *s))(va_list ptr_arr, paramsvar *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary};
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rotl3},
		{NULL, NULL}
	};

	int i =	0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
*print_from_to - prints a range of chars
*@start: starting point
*@stop: ending point
*@except: exceptions if any
*Return: no of printed bytes
**/

int print_from_to(char *start, char *stop, char *except)
{
	int total = 0;

	while (start <= stop)
	{
		if (start != except)
			total += _putchar(*start]);
		start++;
	}
	return (total);
}
