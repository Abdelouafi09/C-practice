#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	int row, col, input, valid = 0;
	char c;

	while (valid == 0)
	{
		printf("Enter the size of the pyramid: \n");
		valid = scanf("%d", &input);
		if (valid == 0)
		{
			while ((c = getchar() != '\n') && c != EOF)
			{
				continue;
			}
			printf("Enter a number not a character!\n");
		}
	}
	for (row = input; row >= 1; row--)
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
