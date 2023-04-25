#include "main.h"

/**
 * get_flags - detect the special flags and its position
 * @format:the sample of formatted string
 * @i: pionter of the position.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	int j, str_i;
	int flags = 0;
	const char F_characters[] = {'-', '+', '0', '#', ' ', '\0'};
	const int F_name[] = {F_minus, F_plus, F_zero, F_hash, F_space, 0};

	for (str_i = *i + 1; format[str_i] != '\0'; str_i++)
	{
		for (j = 0; F_characters[j] != '\0'; j++)
			if (format[str_i] == F_characters[j])
			{
				flags |= F_name[j];
				break;
			}

		if (F_characters[j] == 0)
			break;
	}

	*i = str_i - 1;

	return (flags);
}

