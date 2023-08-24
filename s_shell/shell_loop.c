#include "shell.h"

/**
 * find_bltin - finds a builtin cmd
 * @info: info struct
 *
 * Return: -1 ==> builtin not found, otherwise the builtin index
 */
int find_bltin(inf *info)
{
	int i, bltin_index = -1;
	bltin_t bltin_tab[] = {
		{"exit", _myexit},
		{"env", _env},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (i = 0; bltin_tab[i].type; i++)
		if (_strcmp(info->argv[0], bltin_tab[i].type) == 0)
		{
			info->line_count++;
			bltin_index = bltin_tab[i].func(info);
			break;
		}
	return (bltin_index);
}


/**
 * cmd_find - finds a cmd in PATH
 * @info: info struct
 *
 */
void cmd_find(inf *info)
{
	char *path = NULL;
	int i, k;

	info->cmd_path = info->argv[0];
	if (info->line_count_flag == 1)
	{
		info->line_count++;
		info->line_count_flag = 0;
	}
	for (i = 0, k = 0; info->arg[i]; i++)
		if (!is_delim(info->arg[i], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->cmd_path = path;
		cmd_fork(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_command(info, info->argv[0]))
			cmd_fork(info);
		else if (*(info->arg) != '\n')
		{
			info->stat = 127;
			print_err(info, "not found\n");
		}
	}
}


/**
 * h_sh - shell loop
 * @info: info struct
 * @av: av from main()
 *
 * Return: 0 on success, 1 on error, or error code
 */
int h_sh(inf *info, char **av)
{
	ssize_t r = 0;
	int bltin_ret = 0;

	while (r != -1 && bltin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_errputchar(BUF_FH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			bltin_ret = find_bltin(info);
			if (bltin_ret == -1)
				cmd_find(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->stat)
		exit(info->stat);
	if (bltin_ret == -2)
	{
		if (info->err_int == -1)
			exit(info->stat);
		exit(info->err_int);
	}
	return (bltin_ret);
}


/**
 * cmd_fork - fork exec thread to run cmd
 * @info: info struct
 *
 */
void cmd_fork(inf *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->cmd_path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->stat));
		if (WIFEXITED(info->stat))
		{
			info->stat = WEXITSTATUS(info->stat);
			if (info->stat == 126)
				print_err(info, "Permission denied\n");
		}
	}
}
