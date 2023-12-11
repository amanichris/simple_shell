#include "shell.h"

/**
 * _minhistory -> displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *              constant function prototype.
 *
 *  Return: Always 0 Success
 */
int _minhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias -> sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *ptr, r;
	int ret;

	ptr = _strchr(str, '=');
	if (!ptr)
	return (1);
	r = *ptr;
	*ptr = 0;
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*ptr = r;
	return (ret);
}

/**
 * set_alias -> sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *ptr;

	ptr = _strchr(str, '=');
	if (!ptr)
	return (1);
	if (!*++ptr)
	return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias -> prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *ptr = NULL, *a = NULL;

	if (node)
	{
	ptr = _strchr(node->str, '=');
	for (a = node->str; a <= ptr; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(ptr + 1);
		_puts("'\n");
	return (0);
	}
return (1);
}

/**
 * _myalias -> mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *
 *  Return: Always 0 Success
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *ptr = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
	node = info->alias;
	while (node)
	{
	print_alias(node);
	node = node->next;
	}
	return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
	ptr = _strchr(info->argv[i], '=');
	if (ptr)
	set_alias(info, info->argv[i]);
	else
	print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
