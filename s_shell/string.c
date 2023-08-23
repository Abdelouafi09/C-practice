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
 * _strcmp - compare two strings
 *
 * @s1: first string
 *
 * @s2: second string
 *
 * Return: an integer that segnify the result
 */
int _strcmp(char *s1, char *s2)
{
	int len, i, c;

	len = strlen(s1);
	for (i = 0; i < len && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		c = s1[i] - s2[i];
		if (c == 0)
			continue;
		else
			break;
	}
	return (c);
}
/*###########################33*/



/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
