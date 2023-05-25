#include <stdio.h>

/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	int row, col, input, valid = 0;
	char c;

	while (valid != 1)
	{
		printf("Enter the size of your pyramid:\n");
		valid = scanf("%d", &input);
		while ((c = getchar()) != '\n' && c != EOF)
			continue;
	}

	for (row = input; row >= 1; row--)
	{
		for (col = 1; col <= row; col++)
		{
			if (col == 1)
				printf("*");
			else
				printf(" *");
		}
		printf("\n");
	}
	return (0);
}
