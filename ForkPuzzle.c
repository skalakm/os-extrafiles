/*
 * Puzzle to illustrate the idea that the parent's 
 * address space is cloned in the child process.
 */
 
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {