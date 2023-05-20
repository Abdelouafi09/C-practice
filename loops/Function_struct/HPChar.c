#include "main.h"
/**
 * HPChar - half pyramid of letters
 * @c: character to print its sequence
 * Return: 0
 */
int HPChar(char c)
{
	int row, col, con;
	char alph;

	if ((c >= 'a' && c <= 'z'))
		alph = 'a';
	else
		if (c >= 'A' && c <= 'Z')
			alph = 'A';
		else
			return (0);
	con = c - alph + 1;
	for (row = 1; row <= con; row++)
	{
		for (col = 1; col <= row; col++)
		{
			if (col == 1)
				printf("%c", alph);
			else
				printf(" %c", alph);
			/*alph++;*/
		}
		/*alph = alph - row;*/
		alph++;
		printf("\n");
	}
	return (0);
}
