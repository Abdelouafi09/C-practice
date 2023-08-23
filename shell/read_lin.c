#include <unistd.h>
#include <stdio.h>

int main(void)
{
	char *line = NULL;
	size_t len;

	printf("$ ");
	getline(&line, &len, stdin);
	printf("%s", line);
	return (0);
}
