#include "main.h"

/**
 * _memcpy - copies information between void pointers.
 * @new: destination
 * @ptr: source
 * @size: size of the new pointer.
 *
 * Return: no return.
 */
void _memcpy(void *new, const void *ptr, unsigned int size)
{
	unsigned int i;
	char *char_ptr = (char *)ptr;
	char *char_new = (char *)new;

	for (i = 0; i < size; i++)
		char_new[i] = char_ptr[i];
}

/**
 * _realloc - reallocates memory block.
 * @ptr: pointer to the memory previously allocated.
 * @size_o: sizeof the allocated space of ptr.
 * @size_n: size of the new memory block.
 *
 * Return: ptr if size_n == size_o, NULL if malloc fails
 */
void *_realloc(void *ptr, unsigned int size_o, unsigned int size_n)
{
	void *new;

	if (ptr == NULL)
		return (malloc(size_n));

	if (size_n == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (size_n == size_o)
		return (ptr);

	new = malloc(size_n);
	if (new == NULL)
		return (NULL);

	if (size_n < size_o)
		_memcpy(new, ptr, size_n);
	else
		_memcpy(new, ptr, size_o);

	free(ptr);
	return (new);
}

/**
 * _realloc_d - reallocates a memory block of a double pointer.
 * @ptr: double pointer to the memory previously allocated.
 * @size_o: size, in bytes, of the allocated space of ptr.
 * @size_n: new size, in bytes, of the new memory block.
 *
 * Return: ptr if size_n == size_o, NULL if malloc fails
 */
char **_realloc_d(char **ptr, unsigned int size_o, unsigned int size_n)
{
	char **new;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * size_n));

	if (size_n == size_o)
		return (ptr);

	new = malloc(sizeof(char *) * size_n);
	if (new == NULL)
		return (NULL);

	for (i = 0; i < size_o; i++)
		new[i] = ptr[i];

	free(ptr);

	return (new);
}
