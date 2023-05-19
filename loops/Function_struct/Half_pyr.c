#include <stdio.h>
/**
 * Half_pyr - display half pyramid of given size
 * @a: size of the pyramid
 * Return: 0
 */
int Half_pyr(int a)
{
	int row, col;

	for (row = 0; row < a; row++)
	{
		for (col = 0; col <= row; col++)
		{
			if (col == 0)
				printf("*");
			else
				printf(" *");
		}
		printf("\n");
	}
	return (0);
}
