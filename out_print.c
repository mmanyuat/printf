#include "main.h"
#include <stdarg.h>

/**
 * out_print - function to print a string
 * @format: the string
 * @aptr:pointer to the string
 * Return: pointer to the integer
 */

int out_print(const char *format, va_list aptr)
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
	default:
	len += _putchar('%');
	len += write(STDOUT_FILENO, &(*format), 1);
	break;
	}
	return (len);
}


/**
 * print_str - function to print a string
 * @str:the string
 * Return: the number of the string
 */

int print_str(char *str)
{
	int count = 0;

	while (*str == '\0')
	{
	_putchar((int)*str);
	count++;
	str++;
	}
	return (count);
}

/**
 * print_digit - function to print out digits
 * @n: the number
 * @base:its base
 * Return:the digit
 */

int print_digit(long n, int base)
{
	int count;
	char symbol[] = "0123456789";

	if (n < 0)
	{
	write(STDOUT_FILENO, "-", 1);
	return (print_digit(-n, base) + 1);
	}
	else if (n < base)
	return (_putchar(symbol[n]));
	else
	{
	count = print_digit(n / base, base);
	return (count + print_digit(n % base, base));
	}
}
