#include <stdio.h>
/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	int i, j, valid = 0, con, many = 0;
	char input, alph, c;

	while (valid == 0)
	{
		printf("Enter the character class of the pyramid:\n");
		scanf(" %c", &input);
		/*check if the char is letter*/
		if ((input <= 'z' && input >= 'a') || (input <= 'Z' && input >= 'A'))
			valid = 1;
		/*check for many char*/
		while ((c = getchar()) != '\n' && c != EOF)
		{
			many = 1; /*indicates that more than one character given*/
			valid = 0; /*prevent the first character is a letter*/
			continue;
		}
		/*error message for many char case*/
		if (many == 1)
			printf("Error! enter a single char.\n");
		/*error message for invalid char*/
		else
			if (valid == 0)
				printf("The character should be lowercase or uppercase letter.\n");
		/*prevent displaying many char case error message every time*/
		many = 0;
	}
	if (valid == 1)
	{
		/*uppercase*/
		if (input <= 'Z' && input >= 'A')
			alph = 'A';
		else
			/*lowercase*/
			if (input <= 'z' && input >= 'a')
				alph = 'a';
		/*calculate the number of char to print in both cases*/
		con = input - alph + 1;
		/*print the half pyramid*/
		for (i = 1; i <= con; i++)
		{
			for (j = 1; j <= i; j++)
			{
				if (j == 1)
					printf("%c", alph);
				else
					printf(" %c", alph);
			}
			alph++;
			printf("\n");
		}
	}
	return (0);
}
