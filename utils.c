#include "main.h"
/**
 *
 *  * is_printable - function that evaluates if a char is printable
 *   * @c: Parameter passed in
 *     * Return: 1 if c is printable, 0 otherwise
 *      */

int is_printable(char c)

{

	if (c >= 32 && c < 127)

		return (1);


	return (0);

}


/**
 *
 *  * append_hexa_code - write  ascci in hexdecimal code to the buffer
 *   * @buffer: Array of chars.
 *
 *    * @i: Index at which to start appending.
 *
 *     * @ascii_code: ASSCI CODE.
 *
 *      * Return: Always 3
 *
 *       */

int append_hexa_code(char ascii_code, char buffer[], int i)

{

	char map_to[] = "0123456789ABCDEF";

	/* The hexa format code is always 2 digits long */

	if (ascii_code < 0)

		ascii_code *= -1;


	buffer[i++] = '\\';

	buffer[i++] = 'x';


	buffer[i++] = map_to[ascii_code / 16];

	buffer[i] = map_to[ascii_code % 16];


	return (3);

}


/**
 *
 *  * is_digit - function that verify if a char is a digit
 *
 *   * @m: parameter entered
 *     * Return: 1 if c is a digit, 0 otherwise
 *      */

int is_digit(char m)

{

	if (m >= '0' && m <= '9')

		return (1);


	return (0);

}


/**
 *
 *  * convert_size_number - specified cast on a number in a function
 *
 *   * @number: Number to be casted.
 *
 *    * @size: Number indicating the type to be casted.
 *
 *     *
 *
 *      * Return: Casted value of num
 *
 *       */

long int convert_size_number(long int number, int size)

{

	if (size == S_LONG)

		return (number);

	else if (size == S_SHORT)

		return ((short)number);

	return ((int)number);

}


/**
 *
 *  * convert_size_unsgnd - Casts a number to the specified size
 *
 *   * @numb: Number to be casted
 *
 *    * @size: Number indicating the type to be casted
 *
 *     *
 *
 *      * Return: Casted value of num
 *
 *       */

long int convert_size_unsgnd(unsigned long int numb, int size)

{

	if (size == S_LONG)

		return (numb);

	else if (size == S_SHORT)

		return ((unsigned short)numb);


	return ((unsigned int)numb);

}
