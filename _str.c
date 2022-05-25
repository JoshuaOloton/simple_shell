#include "main.h"

/**
 * _cat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_cat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * *_cpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_cpy(char *dest, char *src)
{
	size_t a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _cmp - Function that compares two strings
 * @str1: str1
 * @str2: str2
 * Return: 0.
 */
int _cmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
		i++;

	if (str1[i] < str2[i])
		return (-1);
	if (str1[i] > str2[i])
		return (1);

	return (0);
}

/**
 * _chr - locates a character in a string,
 * @str: string.
 * @ch: character.
 * Return: the pointer to the first occurrence of the character ch.
 */
char *_chr(char *str, char ch)
{
	unsigned int i;

	i = 0;
	for (; *(str + i) != '\0'; i++)
		if (*(str + i) == ch)
			return (str + i);
	if (*(str + i) == ch)
		return (str + i);

	return ('\0');
}

/**
 * _spn - gets the len of a prefix substring.
 * @str: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _spn(char *str, char *accept)
{
	int i, j, bool;

	i = 0;
	while (*(str + i) != '\0')
	{
		bool = 1;
		j = 0;
		while (*(accept + j) != '\0')
		{
			if (*(str + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
			j++;
		}
		if (bool == 1)
			break;
		i++;
	}
	return (i);
}
