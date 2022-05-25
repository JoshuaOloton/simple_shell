#include "main.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _len(name);
	len_value = _len(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_cpy(new, name);
	_cat(new, "=");
	_cat(new, value);
	_cat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @d_sh: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, data_struct *d_sh)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; d_sh->_environ[i]; i++)
	{
		var_env = _strdup(d_sh->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_cmp(name_env, name) == 0)
		{
			free(d_sh->_environ[i]);
			d_sh->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	d_sh->_environ = _realloc_d(d_sh->_environ, i, sizeof(char *) * (i + 2));
	d_sh->_environ[i] = copy_info(name, value);
	d_sh->_environ[i + 1] = NULL;
}

/**
 * _cmpenv - compares env variables names
 * with the name passed.
 * @d_sh: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _cmpenv(data_struct *d_sh)
{

	if (d_sh->args[1] == NULL || d_sh->args[2] == NULL)
	{
		call_error(d_sh, -1);
		return (1);
	}

	set_env(d_sh->args[1], d_sh->args[2], d_sh);

	return (1);
}

/**
 * _delenv - deletes a environment variable
 *
 * @d_sh: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _delenv(data_struct *d_sh)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (d_sh->args[1] == NULL)
	{
		call_error(d_sh, -1);
		return (1);
	}
	k = -1;
	for (i = 0; d_sh->_environ[i]; i++)
	{
		var_env = _strdup(d_sh->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_cmp(name_env, d_sh->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		call_error(d_sh, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; d_sh->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = d_sh->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(d_sh->_environ[k]);
	free(d_sh->_environ);
	d_sh->_environ = realloc_environ;
	return (1);
}
