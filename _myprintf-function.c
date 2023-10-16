#include "main.h"

/**
 * You don't need the `Null` variable; just check if `format` is NULL.
 * You should use va_arg to retrieve the character.
 * Use write to print the character.
 * You can use strlen from the string.h library to find the string's length.
 *
 */

int _printf(const char *format, ...)
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

				write(1, str, strlen);
				cha_print += strlen;
			}

			format++;
		}
	}

	va_end(list_args);

	return cha_print;
}

int main()
{
	_printf("omotayo\n");
	_printf("%c\n", 'L');
	_printf("%s\n", "string");
	_printf("%%\n");
	return 0;
}

