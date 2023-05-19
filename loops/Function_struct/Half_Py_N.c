#include "main.h"
#include <stdio.h>
/**
 * Half_Py_N - display a half pyramid of number
 * @size: size of the pyramid
 * Return: 0
 */
int Half_Py_N(int size)
{
	int row, col;

	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= row; col++)
		{
			if (col == 1)
				printf("%d", col);
			else
				printf(" %d", col);
		}
		printf("\n");
	}
	return (0);
}
