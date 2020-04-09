#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*	SIGTERM Finalizacio controlada. Es la senial utilizada para indicarle a un proceso que dene terminar su ejecucion.
La rutina de tratamiento de esta senial se encarga de tomar las acciones necesarias para dejar al proceso
en un estado coherente y a continuacion finalizar su ejecucion con una llamada a exit
*/

int main(int argc, char const *argv[])
{
	int pid;
	pid = fork();
	if (!pid) {
		/*Codigo del proceso hijo*/
		while(1) {
			printf("Hijo: PID = %d\n", getpid());
			printf("Mi Padre es: %d\n", getppid() );
			sleep(1);
		}
	}

	sleep(10);
	printf("Padre: Terminacion del proceso %d\n", pid);
	kill(pid, SIGTERM);
	exit(0);

	return 0;
}