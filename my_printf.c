#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unisted>

/**
 * _printf - A a variadic function that takes number of string
 * @format:this are the variable number of string
 * ...:the elipses
 * Return: the number of strings
 */

int _printf(const char *format, ...)
{
	va_list aptr;
	int count = 0;

	va_start(aptr, format);
	if (format == NULL)
	return (-1);
	while (*format != '\0')
	{
	if (*format == '%')
	{
	format++;
	count += out_print(format, aptr);
	}
	else
	count += write(STDOUT_FILENO, &(*format), 1);
	format++;
	}
	va_end(aptr);
	return (count);
}
