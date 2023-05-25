#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	int row, col, input, space, valid = 0;
	char c;

	while (valid == 0)
	{
		printf("Enter your pyramid size:\n");
		valid = scanf("%d", &input);
		if (valid == 0)
		{
			while ((c = getchar() != '\n') && c != EOF)
				continue;
			printf("You should enter a number not a character!\n");
		}
	}
	for (row = 1; row <= input; row++)
	{
		col = 1;
		for (space = 1; space <= input - row; space++)
			printf("  ");
		while (col <= 2 * row - 1)
		{
			if (col == 1)
				printf ("*");
			else
				printf (" *");
			col++;
		}
		printf("\n");
	}
	return (0);
}
