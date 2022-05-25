
#include "main.h"

/**
 * rev_string - reverses a string.
 * @str: input string.
 * Return: no return.
 */
void rev_string(char *str)
{
	int ct = 0, i, j;
	char *str, temp;

	while (ct >= 0)
	{
		if (str[ct] == '\0')
			break;
		ct++;
	}
	str = str;

	for (i = 0; i < (ct - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
