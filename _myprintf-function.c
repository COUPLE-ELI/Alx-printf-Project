#include "main.h"

<<<<<<< HEAD
void print_buffer(char buffer[], int *buff_ind);

/**
 *
 *  * _printf - underscore printf function declaled
 *
 *   * @format: parameter passed into the function
 *
 *    * Return: Printed chars.
 *
 *     */
=======
/**
 * You don't need the `Null` variable; just check if `format` is NULL.
 * You should use va_arg to retrieve the character.
 * Use write to print the character.
 * You can use strlen from the string.h library to find the string's length.
 *
 */
>>>>>>> 2f79d9478f1b165ee6ea5c16d9bba5624bef7674

int _printf(const char *format, ...)

{

	int printed = 0, printd_chars = 0;

	int k;

	int flags, width, precision, size, buff_ind = 0;

	va_list list;

	char buffer[BUFF_SIZE];


	if (format == NULL)

		return (-1);


	va_start(list, format);


	for (k = 0; format && format[k] != '\0'; k++)

	{

		if (format[k] != '%')

		{

			buffer[buff_ind++] = format[k];

			if (buff_ind == BUFF_SIZE)

				print_buffer(buffer, &buff_ind);

			/* write(1, &format[k], 1);*/

			printd_chars++;

		}

		else

		{

			print_buffer(buffer, &buff_ind);

			flags = get_flags(format, &k);

			width = get_width(format, &k, list);

			precision = get_precision(format, &k, list);

			size = get_size(format, &k);

			++k;

			printed = handle_print(format, &k, list, buffer,

					flags, width, precision, size);

			if (printed == -1)

				return (-1);

			printd_chars += printed;

		}

	}


	print_buffer(buffer, &buff_ind);


	va_end(list);


	return (printd_chars);

}


/**
 *
 * print_buffer - Prints the contents of the buffer if it exist 
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */

void print_buffer(char buffer[], int *buff_ind)

{
	int cha_print = 0;
	va_list list_args;

	if (format == NULL)
		return -1;

	va_start(list_args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			cha_print++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;

			if (*format == '%')
			{
				write(1, format, 1);
				cha_print++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(list_args, int);

				write(1, &c, 1);
				cha_print++;
			}
			else if (*format == 's')
			{
				char *str = va_arg(list_args, char*);

				int strlen = 0;
				while (str[strlen] != '\0')
					strlen++;

<<<<<<< HEAD
	if (*buff_ind > 0)

		write(1, &buffer[0], *buff_ind);


	*buff_ind = 0;

=======
				write(1, str, strlen);
				cha_print += strlen;
			}

			format++;
		}
	}

	va_end(list_args);

	return cha_print;
>>>>>>> 2f79d9478f1b165ee6ea5c16d9bba5624bef7674
}

int main()
{
	_printf("omotayo\n");
	_printf("%c\n", 'L');
	_printf("%s\n", "string");
	_printf("%%\n");
	return 0;
}

