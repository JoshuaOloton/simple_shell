#include "main.h"

/**
 * sig_handl - Handle the crtl + c call in prompt
 * @sig: Signal handler
 */
void sig_handl(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
