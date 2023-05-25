#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	int row, col, valid, input;
	char c;

	valid = 0;
	while (valid == 0)
	{
		printf("Enter the size of your pyramid:\n");
		valid = scanf("%d", &input);
		while ((c = getchar()) != '\n' && c != EOF)
			continue;
	}

}
