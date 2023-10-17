#include "main.h"


/**
 *
 *  * get_width - Func to calculates the width for printing
 *   * @format: Formatted string in which to print the arguments.
 *    * @i: List of arguments to be printed.
 *     * @list: list of arguments
 *       * Return: width.
 *        */

int get_width(const char *format, int *i, va_list list)

{

	int width = 0;
	
	int cacr_i;

	for (cacr_i = *i + 1; format[cacr_i] != '\0'; cacr_i++)

	{

		if (is_digit(format[cacr_i]))

		{

			width *= 10;

			width += format[cacr_i] - '0';

		}

		else if (format[cacr_i] == '*')

		{

			cacr_i++;

			width = va_arg(list, int);

			break;

		}

		else

			break;

	}


	*i = cacr_i - 1;


	return (width);
}
