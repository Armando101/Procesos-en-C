#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     //Necesaria para usar pid_t y las funciones getpid

//La funcion fork cera una proceso el cual sera una replica del proceso que lo creo 
    //Si el pid=0 es un proceso hijo
    //pid > 0     Proceso padre
    //pid = -1    Erro


int main(int argc, char const *argv[]) {
	int i = 0;
	switch (fork()) {
		case -1:
			perror("Error al crear procesos");
			exit(-1);
			break;
		case 0:
			while(i<10) {
				sleep(1);
				printf("\t\tSoy el proceso hijo: %d mi id es: %d y el de mi padre es %d\n", i++, getpid(), getppid());
			}
			break;
		default:
			while (i<10) {
				printf("\tSoy el proceso padre: %d mi id es: %d\n", i++, getpid());
				sleep(2);
			}
	}
	exit(0);
	return 0;
}