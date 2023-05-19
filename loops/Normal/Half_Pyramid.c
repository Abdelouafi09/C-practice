#include <stdio.h>
/**
 * main - entry point
 * Return: return 0
 */
int main(void)
{
	int i, j, size;

	printf("Enter the size of your pyramid:\n");
	scanf("%d", &size);
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
