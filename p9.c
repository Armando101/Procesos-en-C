#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

//SIGUSR1: Señal numero 1 de usuario. Esta señal está reservada para uso del programador.

void manejador_SIGUSR1(); 
void manejador_SIGTERM(); 

int main () {
    signal (SIGTERM, manejador_SIGTERM);
    signal (SIGUSR1, manejador_SIGUSR1);
    printf("%d\n",getpid());
    while(1)
        pause();
}

void manejador_SIGTERM() {
    printf("Terminacion del proceso %d a peticion del usuario\n", getpid());
    exit(-1);
}

void manejador_SIGUSR1() {
    //signal(sig, SIG_IGN);
    printf("%d\n", rand());
//    signal(sig, manejador_SIGUSR1);
}