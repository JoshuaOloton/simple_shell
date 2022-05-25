#include "main.h"

/**
 * err_msg - err message for env in get_env.
 * @d_sh: data relevant (counter, arguments)
 * Return: err message.
 */
char *err_msg(data_struct *d_sh)
{
	char *message;
	int len;
	char *err;
	char *ct;

	ct = _atos(d_sh->counter);
	message = ": Unable to add/remove from environment\n";
	len = _len(d_sh->argv[0]) + _len(ct);
	len += _len(d_sh->args[0]) + _len(message) + 4;
	err = malloc(sizeof(char) * len + 1);
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
	_cat(err, message);
	_cat(err, "\0");
	free(ct);

	return (err);
}
/**
 * path_perm_err - path and failure denied permission err msg
 * @d_sh: count, arg
 *
 * Return: The err string.
 */
char *path_perm_err(data_struct *d_sh)
{
	int len;
	char *ct;
	char *err;

	ct = _atos(d_sh->counter);
	len = _len(d_sh->argv[0]) + _len(ct);
	len += _len(d_sh->args[0]) + 24;
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
	_cat(err, ": Permission denied\n");
	_cat(err, "\0");
	free(ct);
	return (err);
}
