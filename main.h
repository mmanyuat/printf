#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_str(char *str);
int out_print(const char *format, va_list aptr);
int print_digit(long n, int base);
#endif
