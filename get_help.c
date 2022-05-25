#include "main.h"

/**
 * get_help - function that retrieves help messages according builtin
 * @d_sh: data structure (args and input)
 * Return: Return 0
*/
int get_help(data_struct *d_sh)
{

	if (d_sh->args[1] == 0)
		_help_general();
	else if (_cmp(d_sh->args[1], "cmpenv") == 0)
		_help_cmpenv();
	else if (_cmp(d_sh->args[1], "env") == 0)
		_help_env();
	else if (_cmp(d_sh->args[1], "delenv") == 0)
		_help_delenv();
	else if (_cmp(d_sh->args[1], "help") == 0)
		_help();
	else if (_cmp(d_sh->args[1], "exit") == 0)
		_help_exit();
	else if (_cmp(d_sh->args[1], "cd") == 0)
		_help_cd();
	else if (_cmp(d_sh->args[1], "alias") == 0)
		_help_alias();
	else
		write(STDERR_FILENO, d_sh->args[0],
		      _len(d_sh->args[0]));

	d_sh->stat = 0;
	return (1);
}
