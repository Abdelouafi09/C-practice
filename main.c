#include <stdio.h>
#define min(X, Y) ((X) < (Y) ? printf("%d\n", X) : printf("%d\n", Y))
int main(void)
{

	min(5, 6);
	min(100, 6);
	min(50, 60);
}
