#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//SIGINT Interrupcion. Se envia a todo proceso asociado con una terminal de control cuando se pulsan 
//las teclas de interupcion Ctrl-C

void manejador_SIGINT (int sig) {
	printf(" Senial numero recibida.\n");
}

int main(int argc, char const *argv[]) {
	if (signal (SIGINT, manejador_SIGINT)==SIG_ERR) {
		printf("Error\n");
		exit(-1);
	}
	while (1) {
		printf("En espera de Ctrl-C\n");
		sleep(999);
	}
	return 0;
}