#include "main.h"

/**
 * _bn_cmd - builtin commands
 * @cmd: command
 * Return: function pointer of the builtin command
 */
int (*_bn_cmd(char *cmd))(data_struct *)
{
	bn_t bn[] = {
		{ "env", _env },
		{ "exit", sh_exit },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", change_cd },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int i;

	for (i = 0; bn[i].name; i++)
	{
		if (_cmp(bn[i].name, cmd) == 0)
			break;
	}

	return (bn[i].g);
}
