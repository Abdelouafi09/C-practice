#include <stdio.h>
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int row, col, size, i;
	char c;

	do{

		printf("Enter the size of your pyramid: ");
		i = scanf("%d", &size);
		if (i != 1)
		{
			while ((c = getchar()) != '\n' && c != EOF)
				continue;
		}
	}while (i != 1);
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
