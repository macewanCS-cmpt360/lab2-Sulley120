/*Question 2

For the second question I used fork() once again to create a child and parent.
Also, I created a new text file using the open commmand. I set the oflags
of open() to O_CREAT (creates the file), O_RDWR (allows read and write access
to file), and O_TRUNC (clears all data from the file). then I set the mode to
'0700' to give the fire read write and execute access. Then I make both the
parent and the child write to the newly created file after checking that
they can both access the file descriptor


From my testing it can be seen that yes, both the child and the parent are 
able to access the created file descriptor (being the
number 3). When making them write to the file
concurrently (making it so neither of them is paused by the wait() command)
it can be shown that the parents text is written to the file before the 
child.
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(void)
{
	int new_file = open("test_file.txt", O_CREAT |
	O_RDWR | O_TRUNC, 0700);
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork did not complete\n");
		exit(1);
	}
	/*Child*/
	if (rc == 0) {
		char *child_txt = "Child here! writing to the file.\n";

		printf("Child is now writing to the file\n");
		printf("Child File Descriptor = %d\n", new_file);
		write(new_file, child_txt, strlen(child_txt));
	/*Parent*/
	} else {
		char *parent_txt = "Parent here! writing to the file.\n";

		printf("Parent is now writing to the file\n");
		printf("Parent File Descriptor = %d\n", new_file);
		write(new_file, parent_txt, strlen(parent_txt));
	}
	return 0;
}
