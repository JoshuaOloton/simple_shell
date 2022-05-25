
#include "main.h"

/**
 * rev_string - reverses a string.
 * @str: input string.
 * Return: no return.
 */
void rev_string(char *str)
{
	int ct = 0, i, j;
	char *s, temp;

	while (ct >= 0)
	{
		if (str[ct] == '\0')
			break;
		ct++;
	}
	s = str;

	for (i = 0; i < (ct - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(s + j);
			*(s + j) = *(s + (j - 1));
			*(s + (j - 1)) = temp;
		}
	}
}
