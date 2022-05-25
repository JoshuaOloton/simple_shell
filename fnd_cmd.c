#include "main.h"

/**
 * fnd_cmd - finds builtins and commands
 *
 * @d_sh: data relevant (args)
 * Return: 1 on success.
 */
int fnd_cmd(data_struct *d_sh)
{
	int (*bn)(data_struct *d_sh);

	if (d_sh->args[0] == NULL)
		return (1);

	bn = _bn_cmd(d_sh->args[0]);

	if (bn != NULL)
		return (bn(d_sh));

	return (cmd_exec(d_sh));
}
