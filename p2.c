#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(){
 
    pid_t pid;
 
    printf("Soy el programa principal\n");
    pid = fork();
 
    if(pid < 0)
        printf("Error en la creacion del hijo");
 
    else if(pid != 0) {
        printf("\nHola Mundo soy el padre\n");
        printf("ID %d\n", getpid());
        printf("pid %d\n", pid);
    }
    else {
        printf("\nHola Mundo soy el hijo\n");
        printf("ID %d\n", getpid());
        printf("pid %d\n", pid);
    }
 
    return 0;
 
}