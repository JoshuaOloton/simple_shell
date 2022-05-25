#include "main.h"

/**
 * repeated_char - counts char repetitions
 *
 * @input: input string
 * @idx: index
 * Return: repetitions
 */
int repeated_char(char *input, int idx)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, idx + 1));

	return (idx);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @input: input string
 * @idx: index
 * @last: last char read
 * Return: index of err. 0 when there are no
 * errors
 */
int error_sep_op(char *input, int idx, char last)
{
	int count;

	count = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, idx + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (idx);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (idx);

		if (last == '|')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (idx);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (idx);

		if (last == '&')
		{
			count = repeated_char(input, 0);
			if (count == 0 || count > 1)
				return (idx);
		}
	}

	return (error_sep_op(input + 1, idx + 1, *input));
}

/**
 * first_char - finds index of the first char
 *
 * @input: input string
 * @idx: index
 * Return: 1 if there is an err. 0 in other case.
 */
int first_char(char *input, int *idx)
{

	for (*idx = 0; input[*idx]; *idx += 1)
	{
		if (input[*idx] == ' ' || input[*idx] == '\t')
			continue;

		if (input[*idx] == ';' || input[*idx] == '|' || input[*idx] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax err is found
 *
 * @d_sh: data structure
 * @input: input string
 * @idx: index of the err
 * @bool: to control message err
 * Return: no return
 */
void print_syntax_error(data_struct *d_sh, char *input, int idx, int bool)
{
	char *message, *message2, *message3, *err, *counter;
	int len;

	if (input[idx] == ';')
	{
		if (bool == 0)
			message = (input[idx + 1] == ';' ? ";;" : ";");
		else
			message = (input[idx - 1] == ';' ? ";;" : ";");
	}

	if (input[idx] == '|')
		message = (input[idx + 1] == '|' ? "||" : "|");

	if (input[idx] == '&')
		message = (input[idx + 1] == '&' ? "&&" : "&");

	message2 = ": Syntax err: \"";
	message3 = "\" unexpected\n";
	counter = _atos(d_sh->counter);
	len = _len(d_sh->argv[0]) + _len(counter);
	len += _len(message) + _len(message2) + _len(message3) + 2;

	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(counter);
		return;
	}
	_cpy(err, d_sh->argv[0]);
	_cat(err, ": ");
	_cat(err, counter);
	_cat(err, message2);
	_cat(err, message);
	_cat(err, message3);
	_cat(err, "\0");

	write(STDERR_FILENO, err, len);
	free(err);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to
 * find and print a syntax err
 *
 * @d_sh: data structure
 * @input: input string
 * Return: 1 if there is an err. 0 in other case
 */
int check_syntax_error(data_struct *d_sh, char *input)
{
	int begin = 0;
	int f_char = 0;
	int idx = 0;

	f_char = first_char(input, &begin);
	if (f_char == -1)
	{
		print_syntax_error(d_sh, input, begin, 0);
		return (1);
	}

	idx = error_sep_op(input + begin, 0, *(input + begin));
	if (idx != 0)
	{
		print_syntax_error(d_sh, input, begin + idx, 1);
		return (1);
	}

	return (0);
}
