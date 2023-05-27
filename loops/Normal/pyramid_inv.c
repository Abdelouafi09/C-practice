#include <stdio.h>
/**
 * main - Entry point inverted pyramid
 * Return: 0
 */
int main(void)
{
	int row, col, valid, input, space;
	char c;

	valid = 0;
	while (valid == 0)
	{
		printf("Enter the size of your pyramid:\n");
		valid = scanf("%d", &input);
		while ((c = getchar()) != '\n' && c != EOF)
			continue;
	}
	for (row = input; row >= 1; row--)
	{
		for (space = (input - row); space >= 1; space--)
		{
			printf("  ");
		}
		for (col = ((2 * row) - 1); col >= 1; col--)
		{
			if (col == ((2 * row) - 1))
				printf("*");
			else
				printf(" *");
		}
		printf("\n");
	}
	return (0);

}
