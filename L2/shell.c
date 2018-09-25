#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{

	char *cmdline;
	char *token = NULL;
	int i, rc, wc;
	char *args[10];

	cmdline = calloc(1, 1024);
	i = 0;

	printf("prompt> ");
	fgets(cmdline, 1024, stdin);
	fprintf(stderr, "[debug] cmdline = *%s*\n", cmdline);

	token = strtok(cmdline, "\n ");
	while (token != NULL) {
		printf("%s\n", token);
		args[i++] = strdup(token);
		token = strtok(NULL, "\n ");
	}
	rc = fork();
	if (rc < 0) {
		fprintf(stderr, "Fork did not complete\n");
		exit(1);
	}
	if (rc == 0) {
		execvp(args[0], args);
	} else {
		wc = wait(NULL);
	}
	/*args[i] = NULL;*/
	free(cmdline);
	return 0;
}
