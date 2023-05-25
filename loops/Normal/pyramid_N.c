#include <stdio.h>
/**
 * main - Ebtry point print full pyramid of numbers
 * Return: 0
 *
 */
int main(void)
{
	int row, col, input, valid, space;
	char c;

	valid = 0;
	while (valid == 0)
	{
		printf("Enter the size of your pyramid:\n");
		valid = scanf("%d", &input);
		if (valid == 0)
			while ((c = getchar()) != '\n' && c != EOF)
				continue;
	}
	for (row = 1; row <= input; row++)
	{
		if (input > 5)
		for (space = 1; space <= input - row; space++)
			printf("  ");

		col = row;
		while (col < row + (row - 1))
		{
			printf(" %d", col);
			col++;
		}
		while (col >= row)
		{
			printf(" %d", col);
			col--;
		}
		printf("\n");
	}
	return (0);
}
