#include "holberton.h"

/**
 * print_char - print  a char.
 * @list_argument: lista de argumentos
 * envia los argumentos a la funcion _putchar
 * Return: 1.
 */
int print_char(va_list list_argument)
{
	_putchar(va_arg(list_argument, int));

	return (1);
}

/**
 * print_string - print a string.
 * @list_argument: lista de argumentos argumentos
 * Return: i
 */
int print_string(va_list list_argument)
{
	/* declaracion un puntutero que indica el inicio del string */
	char *str;
	/* se declara un int para el contador */
	int i;

	/**
	 * valist = es el objeto de tipo va_list
	 * char * = Este nombre de tipo de dato que se va a utiliza
	 */
	str = va_arg(list_argument, char *);

	/* si s es igual a NULL */
	if (str == NULL)
	{
		/* s es igual a la cadena (null) */
		;
	}
	/**
	 * para i igual a 0; mientras que s en la posicion i sea
	 * diferente a \0; aumente i de uno en uno
	 */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* pasa a la funcion _putchar s en la posicion i */
		_putchar(str[i]);
	}
	/* retorna i */
	return (i);
}

/**
 * count_characters - cuenta cuantos caracteres tiene el numero.
 * @n: argument
 * Return: 0
 */
int count_characters(unsigned int n)
{
	/* se declara una variable contador en 0 */
	int count = 0;
	/* se declara dos variables int positivos */
	unsigned int x, z;

	/* si n (variable recibida por parametro) es diferente a 0 */
	if (n != 0)
	{
		/* ejemplo 1/10 = 0,1 */
		/* ejemplo 5423/10= 542,3 */
		z = (n / 10);
		/* ejemplo 1%10 = 1 */
		/* ejemplo 5423%10 = 3 */
		/**
		 * x igual a n por el modulo de 10
		 * cuando se usa el %10 lo que hace es sacar
		 * el ultimo digito del numero
		 */
		x = (n % 10);
		/* de manera recursiva valida cuantos digitos tiene el numero */
		count += count_characters(z);
		/* lleva la cuentas de los digitos */
		count++;
		/**
		 * envia a la funcion _putchar el valor de x mas '0'
		 * el '0' un numero de un solo digito en su respectivo valor acsii
		 */
		_putchar(x + '0');
		/* retorna el contador */
		return (count);
	}
	/* si no se cumple lo anterior se retora 0 */
	return (0);
}
/**
 * print_integer - print a integer.
 * @list_argument: lista de argumentos
 * Return: b + 1
 */
int print_integer(va_list list_argument)
{
	/* se declaran dos variables enteras y se inicializa b en 0 */
	int a, b = 0;
	/* se declara un entero positivo */
	unsigned int x;

	/**
	 * a es igual a la los argumentos de tiene el listado
	 * que son de tipo entero
	 */
	a = va_arg(list_argument, int);

	/* si a es menor que 0 (numero negativo) */
	if (a < 0)
	{
		/* se llama a la funcion _putchar y se pasa de parametro - (signo menos) */
		_putchar('-');
		/* b igual a uno */
		b = 1;
		/* x es igual a la variable a por menos 1 para volver el numero positivo */
		x = a * (-1);
	}
	else
	{
		/* si a es mayor que 0 x es igual a */
		x = a;
	}

	/* si x es mayor a 9 */
	if (x > 9)
	{
		/* se retorna el valor de count_num y se le suma que que este en b */
		return (b + count_characters(x));
	}
	/**
	 * se llama la funcion _putchar y se pasa por parametro lo que
	 * esta en x, el '0' convirte el numero en codigo ascci
     */
	_putchar(x + '0');

	/* se el numero es de un solo digito se retorna el valor de mas 1 */
	return (1 + b);
}
