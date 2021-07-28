#include "holberton.h"

/**
 * text_format - relaciona los tipos de
 * formato con la funcion correspondiente
 * @arga: trae los argumentos de format
 * @argb: posicion de cada argumento
 * &struct_format:  struct
 * Return: 0.
 */

/* cambiar nombre de funciones */

int (*text_format(const char *arga, int argb))(va_list)
{
	/* lista de argumentos de la estructura struct_format */

	struct_format list[] = {
		/**
		 * primera columna ("") es el formato y la segunda
		 * es la lista de funciones
		 */
		{"c", print_char},
		{"s", print_string},
		{"d", print_integer},
		{"i", print_integer},
		{NULL, NULL},

		/**
		 * % c print a single character
		 * % d print a decimal(base 10) number
		 * % i print an integer in base 10
		 * % s print a string of characters
		 * % % print a percent sign(\% also works)
		 */

	};
	int i;

	for (i = 0; list[i].args != NULL; i++)
	{
		/**
		 * si list en la posicion i es parte de args en la posicion 0
		 * debe ser igual a argu en la posion argb
		 * (arga es el formato y argb es la posicion)
		 */
		if (list[i].args[0] == arga[argb])
		{
			/**
			 * retorna list en la posicion i que
			 * hace parte de func que es la lista de funciones
			 */
			return (list[i].func);
		}
	}
	/* si no cumple las condiciones anteriores retorna NULL */
	return (NULL);
}
