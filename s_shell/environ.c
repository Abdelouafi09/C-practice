#include "shell.h"

/**
 * fill_env_list - fills env linked_list
 * @info: Struct inf
 * Return: Always 0
 */
int fill_env_list(inf *info)
{
	list_t *list_node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&list_node, environ[i], 0);
	info->env = list_node;
	return (0);
}


/**
 * _env - prints curr env
 * @info: Struct inf
 * Return: Always 0
 */
int _env(inf *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _setenv - Initi new env variable,
 *             or modify existing one
 * @info: Struct inf
 *  Return: Always 0
 */
int _setenv(inf *info)
{
	if (info->argc != 3)
	{
		_errputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _unsetenv - Remove an env var
 * @info: Struct inf
 *  Return: Always 0
 */
int _unsetenv(inf *info)
{
	int i;

	if (info->argc == 1)
	{
		_errputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Struct inf
 * @name: env var name
 *
 * Return: env value if exist, NULL if not
 */
char *_getenv(inf *info, const char *name)
{
	list_t *list_node = info->env;
	char *ptr;

	while (list_node)
	{
		ptr = starts_with(list_node->str, name);
		if (ptr && *ptr)
			return (ptr);
		list_node = list_node->next;
	}
	return (NULL);
}
