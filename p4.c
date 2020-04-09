    #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main(){
    printf("Ejemplo de proceso huérfano :B\n");
    printf("Inicio del proceso padre. PID = %d\n",getpid());
    if (fork() == 0){
        printf("Inicio del proceso hijo :v PID = %d, PPID = %d \n",getpid(),getppid());
      //  sleep(1);
        printf(" el proceso queda como Batman :c. PID = %d, PPID = %d",getpid(),getppid());
    }else
        printf("Continuación del padre PID = %d \n", getpid());
 
    printf(" Fin del proceso %d\n\n", getpid());
    exit(0);
}