#include "main.h"

/**
 * free_data - frees data structure
 *
 * @d_sh: data structure
 * Return: no return
 */
void free_data(data_struct *d_sh)
{
	unsigned int i;

	for (i = 0; d_sh->_environ[i]; i++)
	{
		free(d_sh->_environ[i]);
	}

	free(d_sh->_environ);
	free(d_sh->pid);
}

/**
 * set_data - Initialize data structure
 *
 * @d_sh: data structure
 * @argv: argument vector
 * Return: no return
 */
void set_data(data_struct *d_sh, char **argv)
{
	unsigned int i;

	d_sh->argv = argv;
	d_sh->input = NULL;
	d_sh->args = NULL;
	d_sh->stat = 0;
	d_sh->counter = 1;

	for (i = 0; environ[i]; i++)
		;

	d_sh->_environ = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		d_sh->_environ[i] = _strdup(environ[i]);
	}

	d_sh->_environ[i] = NULL;
	d_sh->pid = _atos(getpid());
}

/**
 * main - Entry point
 *
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: 0 on success.
 */
int main(int ac, char **argv)
{
	data_struct d_sh;
	(void) ac;

	signal(SIGINT, sig_handl);
	set_data(&d_sh, argv);
	shell_loop(&d_sh);
	free_data(&d_sh);
	if (d_sh.stat < 0)
		return (255);
	return (d_sh.stat);
}
