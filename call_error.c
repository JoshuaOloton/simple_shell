#include "main.h"

/**
 * call_error - calls the err according the builtin, syntax or permission
 * @d_sh: data structure that contains arguments
 * @eval: err value
 * Return: err
 */
int call_error(data_struct *d_sh, int eval)
{
	char *err;

	switch (eval)
	{
	case -1:
		err = err_msg(d_sh);
		break;
	case 126:
		err = path_perm_err(d_sh);
		break;
	case 127:
		err = error_not_found(d_sh);
		break;
	case 2:
		if (_cmp("exit", d_sh->args[0]) == 0)
			err = error_sh_exit(d_sh);
		else if (_cmp("cd", d_sh->args[0]) == 0)
			err = cd_error(d_sh);
		break;
	}

	if (err)
	{
		write(STDERR_FILENO, err, _len(err));
		free(err);
	}

	d_sh->stat = eval;
	return (eval);
}
