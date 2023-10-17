#include "main.h"


/**
 *
 *  * get_size - Calculates the size to cast the argument
 *    * @i: List of arguments to be printed
 *   * @format: Formatted string in which to print the arguments
 *      * Return: Precision.
 */

int get_size(const char *format, int *i)

{
	
	int size = 0;
	int curr_ii = *i + 1;

	if (format[curr_ii] == 'l')

		size = S_LONG;

	else if (format[curr_ii] == 'h')

		size = S_SHORT;


	if (size == 0)

		*i = curr_ii - 1;

	else

		*i = curr_ii;

	return (size);

}
