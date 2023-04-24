#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTBUF_SIZE 1024
#define BUFFER -1
#define NULLSTR "(null)"

#define PARAMETERS (0, 0, 0, 0, 0, 0, 0, 0, 0, 0)

/**
 * struct parameters - a structure of parameters
 * @unsign: unsigned integer
 * @plus_flag: plus sign
 * @space_flag: space charhcter
 * @hashtag_flag: hashtag sign
 * @zero_flag: zero sign
 * @minus_flag: minus sign
 * @width: the wifth of a string
 * @precision: percent sign
 * @h_modifier: the short sign
 * @l_modifier: the long sign
*/

typedef struct parameters
{
unsigned int unsign	: 1;
unsigned int plus_flag : 1;
unsigned int space_flag	: 1;
unsigned int hashtag_flag : 1;
unsigned int zero_flag	: 1;
unsigned int minus_flag	: 1;
unsigned int width;
unsigned int precision;
unsigned int h_modifier : 1;
unsigned int l_modifier	: 1;
} paramsvar;

/**
 * struct specifier - a structure of specifiers
 * @specifiervar: specificers variabkes used
 * @f: integer used
 */
typedef struct specifier
{
char *specifiervar;
int (*f)(va_list, paramsvar *);
} specifiervar;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list ptr_arr, paramsvar *params);
int print_int(va_list ptr_arr, paramsvar *params);
int print_string(va_list ptr_arr, paramsvar *params);
int print_percent(va_list ptr_arr, paramsvar *params);

/**
 * get_specifier - a function that calls specifiers function
 * @s: pointer to string
 * Return: integer
 */

int (*get_specifier(char *s)) (va_list ptr_arr, paramsvar *params)
int get_print_func(char *s, va_list ptr_arr, paramsvar *params);
int get_flag(char *s, paramsvar *params);
int get_modifier(char *s, paramsvar *params);
char *get_width(char *s, paramsvar *params, va_list ptr_arr);

int print_from_to(char *start, char *stop, char *except);

void init_params(paramsvar *params, va_list ptr_arr);

char *get_precision(char *p, paramsvar *params, va_list ptr_arr);

int _printfj(const char *format, ...);

#endif
