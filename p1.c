#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     //Necesaria para usar pid_t
 
int main(){
    pid_t pid;  //Guarda el ID de un proceso
    
    printf("\nHola Mundo\n");
    pid = fork();   //La funcion fork cera una proceso el cual sera una replica del proceso que lo creo 
    //Si el pid=0 es un proceso hijo
    //pid > 0     Proceso padre
    //pid = -1    Erro
    if(pid != 0){
        printf("\nSoy el proceso abuelo: %d\n",getppid());
        printf("\nSoy el proceso padre: %d\n",getpid());
        printf("\nMi hijo tiene el id: %d\n",pid);
    }
    else{
        printf("\nSoy el proceso hijo: %d\n",getpid());
        printf("\nMi padre tiene el id: %d\n",getppid());
    }
 
}