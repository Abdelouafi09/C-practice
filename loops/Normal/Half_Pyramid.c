#include <stdio.h>
/**
 * main - entry point
 * Return: return 0
 */
int main(void)
{
	int i, j, size, v = 0;
	char c;

	while (v != 1)
	{
	printf("Enter the size of your pyramid:\n");
	v = scanf("%d", &size);
	if (v != 1)
	{
		while ((c = getchar()) != '\n' && c != EOF)
			continue;
	}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (j == 0)
				printf("*");
			else
				printf(" *");
		}
		printf("\n");
	}
	return (0);
}
