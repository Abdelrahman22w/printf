#include "main.h"
/**
 * handle_print - Prints a formatted input based on givens
 * @fmt: Formatted string to modify.
 * @list: List of arguments to be passed.
 * @ind: position of specified argument.
 * @buffer: Buffer array to handle print.
 * @flags: detect flags.
 * @width: get width.
 * @precision: specify Precision.
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int pos, length = 0, printed_chars = -1;
	fmt_s fmt_type[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (pos = 0; fmt_type[pos].fmt != '\0'; pos++)
		if (fmt[*ind] == fmt_type[pos].fmt)
			return (fmt_type[pos].fn(list, buffer, flags, width, precision, size));

	if (fmt_type[pos].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		length += write(1, &fmt[*ind], 1);
		return (length);
	}
	return (printed_chars);
}
