#include <stdio.h>
#include "main.h"
/**
 * main - test the functions
 * Return: 0
 */
int main(void)
{
	printf("--------------- Half Pyramid of * ---------------\n");
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
	printf("--------------- Half Pyramid of int ---------------\n");
	printf("case: 0\n");
	Half_Py_N(0);
	printf("case: 1\n");
	Half_Py_N(1);
	printf("case: 10\n");
	Half_Py_N(10);
	printf("case: -1\n");
	Half_Py_N(-1);
	printf("--------------- Half Pyramid of char ---------------\n");
	printf("case: a\n");
	HPChar('a');
	printf("case: z\n");
	HPChar('z');
	printf("case: A\n");
	HPChar('A');
	printf("case: Z\n");
	HPChar('Z');
	printf("case: 4\n");
	HPChar('4');
	printf("case: *\n");
	HPChar('*');
	return (0);
}
