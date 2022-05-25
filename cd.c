#include "main.h"

/**
 * cd_dot - changes to the parent directory
 *
 * @d_sh: data relevant (environ)
 *
 * Return: no return
 */
void cd_dot(data_struct *d_sh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_strtok_pwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, d_sh);
	dir = d_sh->args[1];
	if (_cmp(".", dir) == 0)
	{
		set_env("PWD", cp_pwd, d_sh);
		free(cp_pwd);
		return;
	}
	if (_cmp("/", cp_pwd) == 0)
	{
		free(cp_pwd);
		return;
	}
	cp_strtok_pwd = cp_pwd;
	rev_string(cp_strtok_pwd);
	cp_strtok_pwd = _strtok(cp_strtok_pwd, "/");
	if (cp_strtok_pwd != NULL)
	{
		cp_strtok_pwd = _strtok(NULL, "\0");

		if (cp_strtok_pwd != NULL)
			rev_string(cp_strtok_pwd);
	}
	if (cp_strtok_pwd != NULL)
	{
		chdir(cp_strtok_pwd);
		set_env("PWD", cp_strtok_pwd, d_sh);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", d_sh);
	}
	d_sh->stat = 0;
	free(cp_pwd);
}

/**
 * cd_to - changes to a directory given
 * by the user
 *
 * @d_sh: data relevant (directories)
 * Return: no return
 */
void cd_to(data_struct *d_sh)
{
	char pwd[PATH_MAX];
	char *dir, *cp_pwd, *cp_dir;

	getcwd(pwd, sizeof(pwd));

	dir = d_sh->args[1];
	if (chdir(dir) == -1)
	{
		call_error(d_sh, 2);
		return;
	}

	cp_pwd = _strdup(pwd);
	set_env("OLDPWD", cp_pwd, d_sh);

	cp_dir = _strdup(dir);
	set_env("PWD", cp_dir, d_sh);

	free(cp_pwd);
	free(cp_dir);

	d_sh->stat = 0;

	chdir(dir);
}

/**
 * cd_previous - changes to the previous directory
 *
 * @d_sh: data relevant (environ)
 * Return: no return
 */
void cd_previous(data_struct *d_sh)
{
	char pwd[PATH_MAX];
	char *p_pwd, *p_oldpwd, *cp_pwd, *cp_oldpwd;

	getcwd(pwd, sizeof(pwd));
	cp_pwd = _strdup(pwd);

	p_oldpwd = get_env("OLDPWD", d_sh->_environ);

	if (p_oldpwd == NULL)
		cp_oldpwd = cp_pwd;
	else
		cp_oldpwd = _strdup(p_oldpwd);

	set_env("OLDPWD", cp_pwd, d_sh);

	if (chdir(cp_oldpwd) == -1)
		set_env("PWD", cp_pwd, d_sh);
	else
		set_env("PWD", cp_oldpwd, d_sh);

	p_pwd = get_env("PWD", d_sh->_environ);

	write(STDOUT_FILENO, p_pwd, _len(p_pwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_pwd);
	if (p_oldpwd)
		free(cp_oldpwd);

	d_sh->stat = 0;

	chdir(p_pwd);
}

/**
 * cd_to_home - changes to home directory
 *
 * @d_sh: data relevant (environ)
 * Return: no return
 */
void cd_to_home(data_struct *d_sh)
{
	char *p_pwd, *home;
	char pwd[PATH_MAX];

	getcwd(pwd, sizeof(pwd));
	p_pwd = _strdup(pwd);

	home = get_env("HOME", d_sh->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", p_pwd, d_sh);
		free(p_pwd);
		return;
	}

	if (chdir(home) == -1)
	{
		call_error(d_sh, 2);
		free(p_pwd);
		return;
	}

	set_env("OLDPWD", p_pwd, d_sh);
	set_env("PWD", home, d_sh);
	free(p_pwd);
	d_sh->stat = 0;
}
