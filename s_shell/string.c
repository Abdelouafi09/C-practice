#include "shell.h"




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
 * _strdup - duplicates string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated str
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ptr;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (len++; len--;)
		ptr[len] = *--str;
	return (ptr);
}


/**
 * _strcat - concatinate string
 * @dest: string to add to
 * @src: string to add
 * Return: return dest string containe both strings
 *
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2, i;

	len1 = strlen(dest);
	len2 = strlen(src);
	for (i = 0; i < len2 && *src != '\0'; i++)
	{
		dest[len1 + i] = src[i];
	}
	dest[len1 + len2] = '\0';
	return (dest);
}

/*###########################33*/


/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
