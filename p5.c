#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <unistd.h>

/* Cuando un proceso finaliza en sistemas Unix, toda su memoria y recursos asociados a él se desreferencian (típico exit)
para que puedan ser usados por otros procesos. En ese espacio de tiempo, la entrada del proceso hijo en la tabla de 
procesos permanece un mínimo tiempo, hasta que el padre conoce que el estado de su proceso hijo es finalizado y entonces 
lo saca de la tabla de procesos.

Para que el proceso padre sepa el estado de su hijo, se le envía una señal SIGCHLD indicando que el proceso hijo ha
finalizado. Esa señal es generada gracias a llamadas al sistema como wait() / waitpid() / waitid().

¿Qué pasa cuando no se usa esos manejadores para conocer el estado de los hijos (función wait() / waitpid() / waitid())? 
Pues que el padre no sabe que su hijo ha terminado y por lo tanto sigue en la lista de procesos.
Los procesos zombie se generan por tanto, cuando el padre no recibe esa señal o bien la ignora, generalmente por bugs
o aplicaciones mal programadas

Es posible, aunque algo poco común, que el padre esté muy ocupado y no pueda en ese momento matar al proceso.
También podría ser que el padre decida tener un proceso zombie en la tabla para reservar ese PID, o que el padre esté
interesado en eliminar los procesos hijos en un determinado orden,…

El tener procesos zombies en la tabla no suele ser un problema, al no ser que su número crezca exponencialmente y 
se ocupen todos los identificadores de procesos que el sistema operativo puede utilizar o bien se necesite el PID 
que el proceso fantasma ocupa. 
*/
 
int main(void){
    pid_t hijo;
    int n=10;
 	hijo = fork();
    if(hijo !=0){
        wait(&hijo);
        printf("Soy el proceso padre %d y espero %d seg antes de terminar :v\n", getpid(), n);
        printf("Mi hijo %d ya llegó :3\n", hijo);
        sleep(n);
    }else
        exit(EXIT_SUCCESS);
 
        return EXIT_SUCCESS;
}