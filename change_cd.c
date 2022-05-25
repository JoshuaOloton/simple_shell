#include "main.h"

/**
 * change_cd - change current directory
 *
 * @d_sh: data relevant
 * Return: 1 on success
 */
int change_cd(data_struct *d_sh)
{
	char *dir;
	int h, h2, dash;

	dir = d_sh->args[1];

	if (dir != NULL)
	{
		h = _cmp("$HOME", dir);
		h2 = _cmp("~", dir);
		dash = _cmp("--", dir);
	}

	if (dir == NULL || !h || !h2 || !dash)
	{
		cd_to_home(d_sh);
		return (1);
	}

	if (_cmp("-", dir) == 0)
	{
		cd_previous(d_sh);
		return (1);
	}

	if (_cmp(".", dir) == 0 || _cmp("..", dir) == 0)
	{
		cd_dot(d_sh);
		return (1);
	}

	cd_to(d_sh);

	return (1);
}
