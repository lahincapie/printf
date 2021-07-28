#include "holberton.h"

/**
 * _printf - produces output according to a format.
 * @format: is a character string. The format string
 * is composed of zero or more directives.
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */

/* prototipo de Holberton */
int _printf(const char *format, ...)
{
	/**
	 * va_list => Este es un tipo adecuado para almacenar la información
	 * que necesitan las tres macros va_start (), va_arg () y va_end ().
	 * va_list recibe la lista de parametros de format
	 */
	va_list list_argument;
	unsigned int i = 0; /* se usa para hacer la iteracion del for */
	unsigned int count = 0;
	/**
	 * almacena cuantas veces se pasa por el for
	 * para contar el numero de carateres format
	 */

	/**
	 * var_start inicializa la variable list_argument
	 * que se utiliza con la lista
	 */
	va_start(list_argument, format);

	/**
	 * si format es falso o format en la posicion 0 es igual a % y
	 * format en la posicion 1 es igual a byte nulo   entonces retorna -1
	 */
	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	/**
	 * i inicia en 0; hasta que format en la
	 * posicion i sea diferente a NULL
	 * aumenta i en uno en uno
	 */
	for (i = 0; format[i] != '\0'; i++)
	{
		/* si format en la poscicion i es igual a % */
		if (format[i] == '%')
		{
			/**
			 * i format en la posicion de i + 1 igual a % imprime %
			 * aumenta count en uno y i en uno
			 */
			if (format[i + 1] == '%')
			{
				_putchar('%');
				count++;
				i++;
			}
			/**
			 * entonces si la funcion text_format con parametros format, i + 1
			 * (text_format trae la lista de las funciones)
			 * es difrente a nulo
			 */
			else if (text_format(format, i + 1) != NULL)
			{
				/* count almacena el valor y despues aumenta el mismo*/
				count += text_format(format, i + 1)(list_argument);
				/* aumenta de uno en uno*/
				i++;
			}
			else
			{
				/**
				 * Si ninguna de las validaciones anteriores se cumple,
				 * se lama a la funcion_putchar y le envia format en la
				 * posicion i y aumenta count en 1
				 */
				_putchar(format[i]);
				count++;
			}
		}
		else
		{
			/**
			 * Si format en la posicion i no tienen un % llama a la funcion
			 * _putchar y le envia format en la posicion i y aumenta count en 1
			 */
			_putchar(format[i]);
			count++;
		}
	}
	/* Finaliza el listado */
	va_end(list_argument);
	/* retorna el valor count */
	return (count);
}
