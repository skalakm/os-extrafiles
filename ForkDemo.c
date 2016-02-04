/*
 * Demonstration of how to fork a new child process
 * and how to tell the difference between the parent 
 * process and the child process.
 */
 
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {

	printf("Parent running\n");
     
	// Create child process.
	int pid = fork();
   
	// fork returns pid of child process in parent
	// and 0 in the child.
	if (pid != 0) {
		printf("Parent running after fork\n");
     
		// wait for one child of this process to finish.
		// if no child is running (i.e. it already finished)
		// then just continue.
		wait(NULL); 
     
		printf("Parent done\n");
	}
	else {
		printf("Child running\n");
		sleep(5);
		printf("Child done\n");
	}
}