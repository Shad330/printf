#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)

/* Function prototypes */
int _printf(const char *format, ...);
int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int write_number(int is_negative, int i, char buffer[], int flags, int width, int precision, int size);
long int convert_size_number(long int n, int size);
int handle_write_char(char c, char buffer[], int flags, int width, int precision, int size);
void print_hex(char buffer[], unsigned long int n, int caps, int len, int *i);

/* Buffer size for number conversion */
#define BUFF_SIZE 1024

/* Flags for printf format specifiers */
#define F_MINUS 1
#define F_PLUS 2
#define F_SPACE 4
#define F_HASH 8
#define F_ZERO 16


#endif /* MAIN_H */
