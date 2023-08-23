#include "shell.h"

/**
 * _strlen - display length
 * @s: char to operate on
 * Return: return an int
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _puts - display a string
 * @str: string to show
 * Return: none
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}


/**
 * _strcpy - copy string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	char *s = dest;

	while (*src != '\0')
	{
		*s++ = *src++;
	}
	*s = '\0';
	return (dest);
}
