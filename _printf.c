#include "holberton.h"

/**
 * _printf - produces output according to a format.
 * @format: is a character string. The format string
 * is composed of zero or more directives.
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	va_list list_argument;
	unsigned int i = 0;
	unsigned int count = 0;

	va_start(list_argument, format);

	/* if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1); */
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			else if (text_format(format, i + 1) != NULL)
			{
				count += text_format(format, i + 1)(list_argument);
				i++;
			}
			else
			{
				_putchar(format[i]);
				count++;
			}
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
	}
	va_end(list_argument);
	return (count);
}
