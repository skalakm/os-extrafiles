#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	
	int segID;

	// Create 4 bytes of shared memory.  Just enough for one int value.
	segID = shmget(IPC_PRIVATE, 4, S_IRUSR | S_IWUSR);

	int pid = fork();
	if (pid != 0) {
		// Get a pointer to the shared bytes for the parent.
		int *sharedInt = (int *) shmat(segID, NULL, 0);

		// Store the value 7 in the shared space.	
		sharedInt[0] = 7;
		
		printf("Parent Before: %d\n", sharedInt[0]);
		wait(NULL);
		printf("Parent After: %d\n", sharedInt[0]);
	}
	else {
		// Get a pointer to the shared bytes for the child.
		int *sharedInt = (int *) shmat(segID, NULL, 0);

		printf("Child Before: %d\n", sharedInt[0]);
		
		// Change the value stored in the shared space.
		sharedInt[0] = 9;

		printf("Child After: %d\n", sharedInt[0]);	
	}	
}