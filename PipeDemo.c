/*
 * Demonstration of how to create and use an Unnamed
 * Unix pipe to communicate between a parent and a
 * child.
 */
 
#include <stdio.h>		// for printf
#include <unistd.h>		// for fork & pipe stuff.
#include <sys/wait.h>		// for wait

#define READ_END 0
#define WRITE_END 1

int main() {

	printf("Parent running\n");
     
	// Create the pipe before the fork so that the child
	// process has a copy of it after the fork.
	int fd[2];
	if (pipe(fd) == -1) {
		printf("Pipe creation failed\n");
		return -1;
	}

	// Create child process.
	int pid = fork();
   
	// fork returns pid of child process in parent
	// and 0 in the child.
	if (pid != 0) {
		printf("Parent running after fork\n");
     
		// The parent will write to the pipe.  So close
		// the read end of the pipe and begin writing data.
		close(fd[READ_END]);
		char *str1 = "printing to the pipe.\0";
		char *str2 = "putting more in pipe.\0";
		
		printf("Parent writing: %s\n", str1);
		write(fd[WRITE_END], str1, 21);
		sleep(3);
		printf("Parent writing: %s\n", str2);
		write(fd[WRITE_END], str2, 21);

		close(fd[WRITE_END]);

		printf("Parent done\n");
	}
	else {
		printf("Child running\n");
		
		// The child will read from the pipe.  So close the
		// write end of the pipe and begin reading until the 
		// parent closes the pipe.
		close(fd[WRITE_END]);
		char buf[1];
		while(read(fd[READ_END], buf, 1) != 0) {
			printf("%s\n",buf);
		}
		close(fd[READ_END]);

		printf("Child done\n");
	}
}