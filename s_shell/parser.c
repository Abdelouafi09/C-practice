#include "shell.h"

/**
 * is_command - check if a file is an executable command
 * @info: info struct
 * @path: path to the file
 *
 * Return: 1 ==> true, 0 otherwise
 */
int is_command(inf *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dupchars - duplicates chars
 * @path_str: PATH string
 * @start: start index
 * @stop: stop index
 * Return: new buffer pointer
 */
char *dupchars(char *path_str, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (path_str[i] != ':')
			buf[k++] = path_str[i];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - finds the given cmd PATH string
 * @info: info struct
 * @path_str: PATH string
 * @cmd: cmd to find
 *
 * Return: found ==> cmd's full path, not found ==> NULL
 */
char *find_path(inf *info, char *path_str, char *cmd)
{
	int i = 0, current_position = 0;
	char *path;

	if (!path_str)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_command(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!path_str[i] || path_str[i] == ':')
		{
			path = dupchars(path_str, current_position, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_command(info, path))
				return (path);
			if (!path_str[i])
				break;
			current_position = i;
		}
		i++;
	}
	return (NULL);
}
