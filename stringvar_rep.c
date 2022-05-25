#include "main.h"

/**
 * conf_env - confirms if the input variable is an environmental variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void conf_env(link_var **h, char *in, data_struct *data)
{
	int row, chr, j, lval;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (j = 1, chr = 0; _envr[row][chr]; chr++)
		{
			if (_envr[row][chr] == '=')
			{
				lval = _len(_envr[row] + chr + 1);
				add_rvar_node(h, j, _envr[row] + chr + 1, lval);
				return;
			}

			if (in[j] == _envr[row][chr])
				j++;
			else
				break;
		}
	}

	for (j = 0; in[j]; j++)
	{
		if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
			break;
	}

	add_rvar_node(h, j, NULL, 0);
}

/**
 * conf_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int conf_vars(link_var **h, char *in, char *st, data_struct *data)
{
	int i, lst, lpd;

	lst = _len(st);
	lpd = _len(data->pid);

	for (i = 0; in[i]; i++)
	{
		if (in[i] == '$')
		{
			if (in[i + 1] == '?')
				add_rvar_node(h, 2, st, lst), i++;
			else if (in[i + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), i++;
			else if (in[i + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[i + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				conf_env(h, in + i, data);
		}
	}

	return (i);
}

/**
 * string_rep - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new len
 * Return: replaced string
 */
char *string_rep(link_var **head, char *input, char *new_input, int nlen)
{
	link_var *indx;
	int i, j, k;

	indx = *head;
	for (j = i = 0; i < nlen; i++)
	{
		if (input[j] == '$')
		{
			if (!(indx->v_len) && !(indx->len_val))
			{
				new_input[i] = input[j];
				j++;
			}
			else if (indx->v_len && !(indx->len_val))
			{
				for (k = 0; k < indx->v_len; k++)
					j++;
				i--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[i] = indx->val[k];
					i++;
				}
				j += (indx->v_len);
				i--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[i] = input[j];
			j++;
		}
	}

	return (new_input);
}

/**
 * stringvar_rep - calls all above functions to replace string into vars
 *
 * @input: input string
 * @d_sh: data structure
 * Return: replaced string
 */
char *stringvar_rep(char *input, data_struct *d_sh)
{
	link_var *head, *indx;
	char *stat, *new_input;
	int olen, nlen;

	stat = _atos(d_sh->stat);
	head = NULL;

	olen = conf_vars(&head, input, stat, d_sh);

	if (head == NULL)
	{
		free(stat);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->v_len);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = string_rep(&head, input, new_input, nlen);

	free(input);
	free(stat);
	free_rvar_list(&head);

	return (new_input);
}
