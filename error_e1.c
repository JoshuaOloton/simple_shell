#include "main.h"

/**
 * cat_cd - concatenates the message for cd err
 *
 * @d_sh: relevant data
 * @message: print message
 * @err: err output
 * @ct: line count
 *
 * Return: err
 */
char *cat_cd(data_struct *d_sh, char *message, char *err, char *ct)
{
	char *flag;

	_cpy(err, d_sh->argv[0]);
	_cat(err, ": ");
	_cat(err, ct);
	_cat(err, ": ");
	_cat(err, d_sh->args[0]);
	_cat(err, message);
	if (d_sh->args[1][0] != '-')
	{
		_cat(err, d_sh->args[1]);
	}
	else
	{
		flag = malloc(3);
		flag[0] = '-';
		flag[1] = d_sh->args[1][1];
		flag[2] = '\0';
		_cat(err, flag);
		free(flag);
	}

	_cat(err, "\n");
	_cat(err, "\0");
	return (err);
}

/**
 * cd_error - err message for cd command in get_cd
 * @d_sh: data relevant (directory)
 * Return: err message
 */
char *cd_error(data_struct *d_sh)
{
	int len, id;
	char *err, *ct, *message;

	ct = _atos(d_sh->counter);
	if (d_sh->args[1][0] != '-')
	{
		message = ": can't cd to ";
		id = _len(d_sh->args[1]);
	}
	else
	{
		message = ": option ain't legal ";
		id = 2;
	}

	len = _len(d_sh->argv[0]) + _len(d_sh->args[0]);
	len += _len(ct) + _len(message) + id + 5;
	err = malloc(sizeof(char) * len + 1);

	if (err == 0)
	{
		free(ct);
		return (NULL);
	}

	err = cat_cd(d_sh, message, err, ct);

	free(ct);

	return (err);
}

/**
 * error_not_found - err msg for cd not found
 * @d_sh: ct, args
 * Return: err message
 */
char *error_not_found(data_struct *d_sh)
{
	int len;
	char *err;
	char *ct;

	ct = _atos(d_sh->counter);
	len = _len(d_sh->argv[0]) + _len(ct);
	len += _len(d_sh->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ct);
		return (NULL);
	}
	_cpy(err, d_sh->argv[0]);
	_cat(err, ": ");
	_cat(err, ct);
	_cat(err, ": ");
	_cat(err, d_sh->args[0]);
	_cat(err, ": not found\n");
	_cat(err, "\0");
	free(ct);
	return (err);
}

/**
 * error_sh_exit - generic err message for exit in get_exit
 * @d_sh: data relevant (counter, arguments)
 *
 * Return: err message
 */
char *error_sh_exit(data_struct *d_sh)
{
	int len;
	char *err;
	char *ct;

	ct = _atos(d_sh->counter);
	len = _len(d_sh->argv[0]) + _len(ct);
	len += _len(d_sh->args[0]) + _len(d_sh->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ct);
		return (NULL);
	}
	_cpy(err, d_sh->argv[0]);
	_cat(err, ": ");
	_cat(err, ct);
	_cat(err, ": ");
	_cat(err, d_sh->args[0]);
	_cat(err, ": number ain't legal: ");
	_cat(err, d_sh->args[1]);
	_cat(err, "\n\0");
	free(ct);

	return (err);
}
