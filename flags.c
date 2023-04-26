#include "main.h"

/**
 * get_flags - gets active flags
 * @format: a string used to print arguments
 * @i: takes a parameter.
 * Return: Flags
*/
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_i;
	int flags = 0;
	const char CHAR_FLAG[] = {'-', '+', '0', '#', ' ', '\0'};
	const int ARR_FLAG[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; CHAR_FLAG[j] != '\0'; j++)
			if (format[curr_i] == CHAR_FLAG[j])
			{
				flags |= ARR_FLAG[j];
				break;
			}

		if (CHAR_FLAG[j] == 0)
			break;
	}

	*i = curr_i - 1;

	return (flags);
}

