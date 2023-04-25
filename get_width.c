#include "main.h"

/**
 * get_width - detect the width of spaces before printing
 * @format: string which we check.
 * @i: pointer for position of %.
 * @list: list of arguments.
 *
 * Return: w.
 */
int get_width(const char *format, int *i, va_list list)
{
	int str_i;
	int w = 0;

	for (str_i = *i + 1; format[str_i] != '\0'; str_i++)
	{
		if (format[str_i] >= '0' && format[str_i] <= '9')
		{
			w *= 10;
			w += format[str_i] - '0';
		}
		else if (format[str_i] == '*')
		{
			str_i++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = str_i - 1;

	return (w);
}

