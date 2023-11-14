#include "main.h"

/**
 * out_print - function to print a string
 * @format: the string
 * @aptr:pointer to the string
 * Return: pointer to the integer
 */

int out_print(const char *format , va_list aptr)
{
	int len = 0;

	switch (*format)
	{
	case 'c':
	len += _putchar(va_arg(aptr, int));
	break;
	case 's':
	len += print_str(va_arg(aptr, char *));
	break;
	case 'd':
	len += print_digit(va_arg(aptr, int), 10);
	break;
	case 'i':
	len += print_digit(va_arg(aptr, unsigned int), 10);
	break;
	case 'x':
	len += print_digit(va_arg(aptr, unsigned int), 16);
	break;
	default
	len += _putchar('%');
	len += write(STDOUT_FILENO, &(*format), 1);
	break;
	}
	return (len);
}

