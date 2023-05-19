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
	return (0);
}
