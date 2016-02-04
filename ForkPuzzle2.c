/*
 * Puzzle to illustrate the idea that the parent
 * and child processes run concurrently.
 */
 
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
 
	int pid = fork();
	if (pid != 0) {
		for (int i=0; i<10; i++) {
			printf("Parent process running.\n");
			sleep(1);
		}
		wait(NULL);  
	}
	else {
		for (int i=0; i<10; i++) {
			printf("Child process running.\n");
			sleep(1);
		}
	}
}