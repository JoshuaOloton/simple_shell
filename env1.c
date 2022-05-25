#include "main.h"

/**
 * env_cmp - compare environment variables
 * @nenv: name of the environment variable
 * @name: name passed
 *
 * Return: 0 if are not equal. Another value if they are.
 */
int env_cmp(const char *nenv, const char *name)
{
	int i;

	i = 0;
	while (nenv[i] != '=')
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
		i++;
	}

	return (i + 1);
}

/**
 * get_env - get an environment variable
 * @name: name of the environment variable
 * @_environ: environment variable
 *
 * Return: value of the environment variable if is found.
 * In other case, returns NULL.
 */
char *get_env(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	ptr_env = NULL;
	mov = 0;
	i = 0;
	while (_environ[i])
	{
		mov = env_cmp(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
		i++;
	}

	return (ptr_env + mov);
}

/**
 * _env - prints the evironment variables
 *
 * @d_sh: data relevant.
 * Return: 1 on success.
 */
int _env(data_struct *d_sh)
{
	int i, j;

	i = 0;
	while (d_sh->_environ[i])
	{
		j = 0;
		while (j = 0; d_sh->_environ[i][j])
			j++;

		write(STDOUT_FILENO, d_sh->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
		i++:
	}
	d_sh->stat = 0;

	return (1);
}
