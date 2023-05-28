#include <stdio.h>
/**
 * main - Entry point build pascal's triangle
 * Return: 0
 */
int main(void)
{
	int row, col, space, input, valid, num;
	char c;

	valid = 0;
	while (valid == 0)
	{
		printf("Enter the size of your Pascale's triangle:\n");
		valid = scanf("%d", &input);
		while ((c = getchar()) != '\n' && c != EOF)
			continue;
	}
	for (row = 0; row < input; row++)
	{
		num = 1;
		for (space = 1; space <= input - row; space++)
			printf("  ");
		for (col = 0; col <= row; col++)
		{
			printf("%4d", num);
			num = num * (row - col) / (col + 1);
		}
		printf("\n");
	}
	return (0);
}
