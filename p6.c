#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>
 
 //En los sistemas Unix un proceso zombie es un proceso que ha terminado su ejecución pero el mismo aún permanece en memoria
 //ya que al terminar un proceso no es eliminado en memoria de manera inmediata, a esto se le conoce como proceso zombie.

int main(void){
    pid_t hijo;
 	hijo = fork();
    if (hijo !=0) {
        printf("Soy el proceso padre y espero 90 segs antes de terminar\n");
        printf("De mi hijo %d no se nada :c\n",hijo);
        sleep(5);
         
    } else
        exit(1);
 
        return 1;
}