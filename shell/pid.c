#include <unistd.h>
#include <stdio.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */

int main(void)
{
	pid_t my_pid, p_pid;

	my_pid = getpid();
	p_pid = getppid();
	printf("The parent process ID is: %u\n", p_pid);
	printf("The child process ID is: %u\n", my_pid);
	return (0);
}
