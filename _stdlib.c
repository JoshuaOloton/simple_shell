#include "main.h"

/**
 * get_len - Get the length of a number.
 * @n: int
 * Return: Length of a number.
 */
int get_len(int n)
{
	unsigned int p;
	int length = 1;

	if (n >= 0)
	{
		p = n;
	}
	else
	{
		length++;
		p = n * -1;
	}
	while (p > 9)
	{
		length++;
		 p /= 10;
	}

	return (length);
}
/**
 * _atos - converts int to string.
 * @n: int number
 * 
 * Return: String.
 */
char *_atos(int n)
{
	unsigned int p;
	int c = get_len(n);
	char *buf;

	buf = malloc(sizeof(char) * c + 1);
	if (buf == 0)
		return (NULL);

	*(buf + c) = '\0';

	if (n >= 0)
	{
		p = n;
	}
	else
	{
		p = n * -1;
		buf[0] = '-';
	}

	c--;
	do {
		*(buf + c) = (p % 10) + '0';
		p = p / 10;
		c--;
	}
	while (p > 0)
		;
	return (buf);
}

/**
 * _atoi - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */
int _atoi(char *str)
{
	unsigned int count = 0;
	unsigned int size = 0;
	unsigned int x = 0;
	unsigned y = 1;
	unsigned z = 1;
	unsigned int i;

	while (*(str + count) != '\0')
	{
		if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
			break;

		if (*(str + count) == '-')
			y *= -1;

		if ((*(str + count) >= '0') && (*(str + count) <= '9'))
		{
			if (size > 0)
				z *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		x = x + ((*(str + i) - 48) * z);
		z /= 10;
	}
	return (x * y);
}
