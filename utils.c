#include "main.h"

/**
 * is_printable - check if char in in ascii code
 * @c: Char to be checked.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
return ((c >= 32) && (c < 127) ? 1 : 0);
}

/**
 * append_hexa_code - Append ascci character to hexadecimal code
 * @buffer: Array of chars.
 * @i: Index of appending begin.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char hex_digits[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = hex_digits[ascii_code / 16];
	buffer[i] = hex_digits[ascii_code % 16];

	return (3);
}

/**
 * is_digit - check if digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - convert a number to specified size
 * @num: Number.
 * @size: cast type.
 *
 * Return: Casted value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_long)
		return (num);
	else if (size == S_short)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - convert unsigned number to specified size
 * @num: Number
 * @size: Number of size
 *
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
		switch (size)
	{
		case S_long:
			return (num);
		case S_short:
			return ((unsigned short) num);
		default:
			return ((unsigned int) num);
	}
}

