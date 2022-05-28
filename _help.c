#include "main.h"

/**
 * _help_env - Help information for the builtin env
 * Return: no return
 */
void _help_env(void)
{
	char *help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, help, _len(help));
	help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, help, _len(help));

}
/**
 * _help_cmpenv - Help information for the builtin cmpenv
 * Return: no return
 */
void _help_cmpenv(void)
{

	char *help = "cmpenv: cmpenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _len(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _len(help));
	help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help, _len(help));
}
/**
 * _help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void _help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _len(help));
	help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help, _len(help));
}


/**
 * _help_general - Entry point for help information for the help builtin
 * Return: no return
 */
void _help_general(void)
{
	char *help = "$ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, help, _len(help));
	help = "These commands are defined internally.Type 'help' to see the list";
	write(STDOUT_FILENO, help, _len(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help, _len(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _len(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _len(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _len(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _len(help));
}
/**
 * _help_exit - Help information fot the builint exit
 * Return: no return
 */
void _help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _len(help));
	help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, help, _len(help));
	help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, help, _len(help));
}
