#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int row, col, size;

	printf("Enter the size of your pyramid: ");
	scanf("%d", &size);
	for (row = 1; row <= size; row++)
	{
		for (col = 1; col <= row; col++)
		{
			if (col == 0)
				printf("%d", col);
			else
				printf(" %d", col);
		}
		printf("\n");
	}
	return (0);
}
