#include "main.h"
/**
 * get_size - calculates the size to cast the argument
 * @format: formatted string to print the arguments
 * @i: List of arguments to be printed
 * Return: Precision (size)
 */
int get_size(const char *format, int *i)
{
	int cur_i = *i + 1;
	int size = 0;

	if (format[cur_i] == 'l')
		size = S_long;
	else if (format[cur_i] == 'h')
		size = S_short;

	if (size == 0)
	{
		*i = cur_i - 1;
	}
	else
		*i = cur_i;

	return (size);
}
