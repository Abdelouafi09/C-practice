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
	valid = input;
	for (row = 1; row <= input; row++)
	{
		for (col = valid; col >= 1; col--)
		{
			if (col == valid)
				printf("*");
			else
				printf(" *");
		}
		printf("\n");
		valid--;
	}
	return (0);
}
