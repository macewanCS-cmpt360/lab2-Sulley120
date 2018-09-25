/*Question 3

For the third question I created a program that created a child and parent
using fork() and had the child print out 'Hello' and the parent print out
'goodbye'. 

To ensure that the child always prints first (i.e 'Hello' prints before
'Goodbye') I found on the linux man pages the function usleep(), which 
allowed me to suspend the execution of the parent process long enough
for the child process to always execute and print first.
*/

/*This was used to make the usleep function work without
warning about implicit declaration found online */

#define _XOPEN_SOURCE 500 

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
		printf("hello\n");
	/*Parent*/
	} else {
		/*found at man7.org/linux/man-pages/man3/usleep.3.html*/
		usleep(10000);
		printf("goodbye\n");
	}
	return 0;
}
