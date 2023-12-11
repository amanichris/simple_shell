#include "shell.h"

/**
 * _chrisexit -> exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */
int _chrisexit(info_t *info)
{
	int exittest;

	if (info->argv[1]) /* If there is an exit arguement */
	{
	exittest = _erratoi(info->argv[1]);
	if (exittest == -1)
	{
	info->status = 2;
	print_error(info, "Illegal number: ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	return (1);
	}
	info->err_num = _erratoi(info->argv[1]);
	return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mincd -> changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _mincd(info_t *info)
{
	char *r, *dir, buffer[1024];
	int childir_ret;

	r = getcwd(buffer, 1024);
	if (!r)
	_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
	dir = _getenv(info, "HOME=");
	if (!dir)
	childir_ret = /* TODO: what should this be? */
	childir((dir = _getenv(info, "PWD=")) ? dir : "/");
	else
	childir_ret = childir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
	if (!_getenv(info, "OLDPWD="))
	{
	_puts(s);
	_putchar('\n');
	return (1);
	}
	_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
	childir_ret = /* TODO: what should this be? */
	childir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
	childir_ret = childir(info->argv[1]);
	if (childir_ret == -1)
	{
	print_error(info, "can't cd to ");
	_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _ohhelp -> changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _ohhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
	_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
