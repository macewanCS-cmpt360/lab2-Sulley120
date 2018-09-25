*Question 1

For the first question I used fork() to create a parent and a child 
process, and had them both change a predetermined x value (x = 30).

For the child I changed the original value of 30 into 65. When both the child
and parent change the variable they receive their own instance of the variable
and in doing so, the parent will change the value to 80 and the child will 
change its value to 65.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	int x = 30;
	int rc = fork();

	if (rc < 0) {
		fprintf(stderr, "Fork did not complete\n");
		exit(1);
	}
	/*Child*/
	if (rc == 0) {
		printf("I am Child.\n");
		printf("----------------------\n");
		printf("X value: %d\n", x);
		x = 65;
		printf("New X value: %d\n", x);
		printf("----------------------\n\n");
	/*Parent*/
	} else {
		printf("I am Parent.\n");
		printf("----------------------\n");
		printf("X value: %d\n", x);
		x = 80;
		printf("New X value: %d\n", x);
		printf("----------------------\n\n");
	}
	return 0;
}
