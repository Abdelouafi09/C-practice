#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void)
{
	int i, id = fork();

	if (id != 0)
                wait(NULL);
	if (id == 0)
	{
		printf("parent: %d child: %d\n", getppid(), getpid());
		for (i = 1; i < 6; i++)
			printf("%d,	", i);
	}
	else
	{
		printf("parent: %d ; main: %d\n", getppid(), getpid());
		for (i = 6; i < 11; i++)
			printf("%d	", i);
	}
	
	printf("\n");
	return (0);
}
