/*
 * Puzzle to illustrate the idea that the parent's 
 * address space is cloned in the child process.
 */
 
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {    int x = 27;        int pid = fork();    if (pid != 0) {        printf("Parent's x before wait is %d\n",x);        x = x + 5;        wait(NULL);          printf("Parent's x after wait is %d\n",x);    }    else {        printf("Child's x before sleep is %d\n",x);        sleep(5);        x = x + 10;        printf("Child's x after sleep is %d\n",x);    }}