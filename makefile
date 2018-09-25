CC = gcc
CFLAGS = -Wall -std=gnu99 -ansi -g

q1: q1.c
	$(CC) $(CFLAGS) q1.c -o q1
q2: q2.c
	$(CC) $(CFLAGS) q2.c -o q2
q3: q3.c
	$(CC) $(CFLAGS) q3.c -o q3
q7: q7.c
	$(CC) $(CFLAGS) q7.c -o q7
shell: shell.c
	$(CC) $(CFLAGS) shell.c -o shell