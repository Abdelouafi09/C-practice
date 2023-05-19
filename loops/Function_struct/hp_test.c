#include <stdio.h>
#include "main.h"
/**
 * main - test the functions
 * Return: 0
 */
int main(void)
{
	printf("size: -1 -----------------------\n");
	Half_pyr(-1);
	printf("size: 0 -----------------------\n");
	Half_pyr(0);
	printf("size: 1 -----------------------\n");
	Half_pyr(1);
	printf("size: 5 -----------------------\n");
	Half_pyr(5);
	printf("size: 1.0 -----------------------\n");
	Half_pyr(1.0);
	return (0);
}
