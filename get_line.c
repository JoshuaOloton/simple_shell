#include "main.h"

/**
 * assign_line - assigns the line var for get_line
 * @lineptr: buf that store the input str
 * @buf: str that is been called to line
 * @n: size of line
 * @size_b: size of buf
 */
void assign_line(char **lineptr, size_t *n, char *buf, size_t size_b)
{

	if (*lineptr == NULL)
	{
		if  (size_b > BUFSIZE)
			*n = size_b;

		else
			*n = BUFSIZE;
		*lineptr = buf;
	}
	else if (*n < size_b)
	{
		if (size_b > BUFSIZE)
			*n = size_b;
		else
			*n = BUFSIZE;
		*lineptr = buf;
	}
	else
	{
		_cpy(*lineptr, buf);
		free(buf);
	}
}
/**
 * get_line - Read input stream
 * @lineptr: store input in buf
 * @n: size of lineptr
 * @stream: stream to read from
 * Return: The number of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int i;
	static ssize_t ipt;
	ssize_t val;
	char *buf;
	char temp = 'z';

	if (ipt == 0)
		fflush(stream);
	else
		return (-1);
	ipt = 0;

	buf = malloc(sizeof(char) * BUFSIZE);
	if (buf == 0)
		return (-1);
	while (temp != '\n')
	{
		i = read(STDIN_FILENO, &temp, 1);
		if (i == -1 || (i == 0 && ipt == 0))
		{
			free(buf);
			return (-1);
		}
		if (i == 0 && ipt != 0)
		{
			ipt++;
			break;
		}
		if (ipt >= BUFSIZE)
			buf = _realloc(buf, ipt, ipt + 1);
		buf[ipt] = temp;
		ipt++;
	}
	buf[ipt] = '\0';
	assign_line(lineptr, n, buf, ipt);
	val = ipt;
	if (i != 0)
		ipt = 0;
	return (val);
}
