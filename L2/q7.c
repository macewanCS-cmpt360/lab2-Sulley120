/*Question 7

For the seventh question I was tasked with once again using fork() to create
two processes, a parent and a child. Once created I was asked to close the
STDOUT and then try to use printf to print a string to the screen.


I found that since the STDOUT_FILENO is closed nothing will print to the
terminal as the shell's output has been closed.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork did not complete\n");
		exit(1);
	}
	/*Child*/
	if (rc == 0) {
		close(STDOUT_FILENO);
		printf("Help! Im trapped in a program!\n");
	/*Parent*/
	} else {
	}
	return 0;
}
