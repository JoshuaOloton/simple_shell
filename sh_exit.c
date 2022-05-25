#include "main.h"

/**
 * sh_exit - exits the shell
 *
 * @d_sh: data relevant (status and args)
 * Return: 0 on success.
 */
int sh_exit(data_struct *d_sh)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (d_sh->args[1] != NULL)
	{
		ustatus = _atoi(d_sh->args[1]);
		is_digit = _isdigit(d_sh->args[1]);
		str_len = _len(d_sh->args[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			call_error(d_sh, 2);
			d_sh->stat = 2;
			return (1);
		}
		d_sh->stat = (ustatus % 256);
	}
	return (0);
}
