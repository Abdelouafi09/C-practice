#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024

void print_prompt() {
	ssize_t bytes_written = write(STDOUT_FILENO, "#cisfun$ ", 9);
	if (bytes_written == -1) {
		perror("write");
		exit(EXIT_FAILURE);
	}
}

void read_input(char **line) {
	size_t len = 0;
	ssize_t bytes_read = getline(line, &len, stdin);
	if (bytes_read == -1) {
		/* Handle Ctrl+D (EOF) */
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	(*line)[strlen(*line) - 1] = '\0'; /* Remove newline character */
}

void execute_command(char *line) {
	pid_t child_pid;
	int status;

	if (strcmp(line, "exit") == 0) {
		exit(EXIT_SUCCESS); /* Exit the shell if user enters "exit"*/
	}

	child_pid = fork();

	if (child_pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0) {
		/* Child process */
		char *args[] = {NULL, NULL}; /* Initialize a null-terminated array*/
		args[0] = line; /* Set the first argument*/
		execve(line, args, NULL);

		/* If execve fails, print error and exit */
		perror("execve");
		_exit(EXIT_FAILURE);
	} else {
		/* Parent process */
		waitpid(child_pid, &status, 0);
	}
}

int main(int ac, char **av) {
	char *line = NULL;

	(void) ac; /* Avoid "unused parameter" warning*/
	(void) av; /* Avoid "unused parameter" warning*/

	while (1) {
		print_prompt();
		read_input(&line);
		execute_command(line);
	}

	/* Clean up */
	free(line);
	return 0;
}

