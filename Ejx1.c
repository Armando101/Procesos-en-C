#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int pid;
	pid = fork();

	switch(pid) {
		case 0: 
			printf("Proceso hijo %d padre %d \n", getpid(), getppid());
		case 1:
			printf("Error\n"); 
			exit(1);
		default:
			printf("Proceso padre %d mi padre %d\n",getpid(), getppid());
	}

	return 0;
}