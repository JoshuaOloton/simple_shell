#include "main.h"

/**
 * del_comments - deletes comments from the input
 *
 * @in: input string
 * Return: input without comments
 */
char *del_comments(char *in)
{
	int i, j;

	j = 0;
	i = 0;
	while (in[i])
	{
		if (in[i] == '#')
		{
			if (i == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[i - 1] == '\t' || in[i - 1] == ';' || in[i - 1] == ' ')
				j = i;
		}
		i++;
	}

	if (j != 0)
	{
		in = _realloc(in, i, j + 1);
		in[j] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @d_sh: input args
 *
 * Return: void
 */
void shell_loop(data_struct *d_sh)
{
	int loop, i_eof;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = readline(&i_eof);
		if (i_eof != -1)
		{
			input = del_comments(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(d_sh, input) == 1)
			{
				d_sh->stat = 2;
				free(input);
				continue;
			}
			input = stringvar_rep(input, d_sh);
			loop = split_commands(d_sh, input);
			d_sh->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}
