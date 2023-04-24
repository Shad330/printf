#include "main.h"

/**
*get_flag - finds the flag func
*@s: the format string
*@params: the parameters struct
*Return: if flag was valid
**/

int get_flag(char *s, paramsvar *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case 'O':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}
/**
*get_modifier - finds the modifier func
*@s: the format string
*@params: the parameters struct
*Return: if modifier was valid
*/

int get_modifier(char *s, paramsvar *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break.;
		case 'l':
			i = params->l_modifier = 1;
		break;
	}
	return (i);
}

