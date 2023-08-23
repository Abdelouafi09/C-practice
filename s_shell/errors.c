#include "shell.h"



/**
 * _errputchar - writes char c to stderr
 * @c: char to print
 *
 * Return: success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _errputchar(char c)
{
	static int i;
	static char b[WR_BUF_SIZE];

	if (c == BUF_FH || i >= WR_BUF_SIZE)
	{
		write(2, b, i);
		i = 0;
	}
	if (c != BUF_FH)
		b[i++] = c;
	return (1);
}

/**
 *_errputs - wrrites str to sderr
 * @s: str to print
 *
 * Return: none
 */
void _errputs(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_errputchar(s[i]);
		i++;
	}
}


/**
 * put_fd - writes char c to fd
 * @c: char to print
 * @fd: filedescriptor to write to
 *
 * Return: Always 1.
 * 
 */
int put_fd(char c, int fd)
{
	static char buf[WR_BUF_SIZE];
	static int i;

	if (c == BUF_FH || i >= WR_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FH)
	{
		buf[i++] = c;
	}

	return (1);
}


/*#######################*/



/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += put_fd(*str++, fd);
	}
	return (i);
}

