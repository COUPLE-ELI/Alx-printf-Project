#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - MY _Printf function
 * @format: format.
 * Return: Printd chars.
 */

int _printf(const char *format, ...)
{
	int h, printed = 0, printd_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (h = 0; format && format[h] != '\0'; h++)
	{
		if (format[h] != '%')
		{
			buffer[buff_ind++] = format[h];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printd_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &h);
			width = get_width(format, &h, list);
			precision = get_precision(format, &h, list);
			size = get_size(format, &h);
			++h;
			printed = handle_print(format, &h, list, buffer,
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
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: input parameter
 *@buff_ind: Index at which to add next char, rep length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
