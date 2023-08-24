#include "shell.h"

/**
 * clear_info - init inf struct
 * @info: struct addrss
 */
void clear_info(inf *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->cmd_path = NULL;
	info->argc = 0;
}

/*############################*/

/**
 * set_info - initializes inf struct
 * @info: struct address
 * @av: argument vector
 */
void set_info(inf *info, char **av)
{
	int i = 0;

	info->file_name = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - frees inf struct fields
 * @info: struct address
 * @all: true if freeing all fields
 */
void free_info(inf *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->cmd_path = NULL;
	if (all)
	{
		if (!info->cmd_buffer)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->mod_environ);
			info->mod_environ = NULL;
		bfree((void **)info->cmd_buffer);
		if (info->read_fd > 2)
			close(info->read_fd);
		_putchar(BUF_FH);
	}
}
