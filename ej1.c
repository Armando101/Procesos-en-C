
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 256
#define LEER 0
#define ESCRIBIR 1

int main(int argc, char const *argv[]) {
  int tuberia[2];
  int pid;
  char mensaje[MAX];

  if(pipe(tuberia) == -1 ){
    perror("PIPE");
    exit(-1);
  }

  //Creacion de proceso hilo
  if((pid = fork()) == -1){
    perror("Fork");
    exit(-1);
  }else if(pid == 0){
    //codigo del proceso hijo la wea fome weon culiao conchesumare desuka jajajajaj equisde
    while (read(tuberia[LEER],mensaje,MAX)>0 && strcmp(mensaje, "FIN\n") != 0) {
      printf("Proceso receptor. mensaje: %s\n",mensaje);
    }
    close(tuberia[LEER]);
    close(tuberia[ESCRIBIR]);
    exit(0);
  }else{
    while((printf("Proceso emisor. Mensaje: \n")!= 0) && (fgets(mensaje, sizeof(mensaje),stdin)!= NULL) &&  (write(tuberia[ESCRIBIR], mensaje,strlen(mensaje)+1) > 0) && (strcmp(mensaje, "FIN\n") != 0))


    close(tuberia[LEER]);
    close(tuberia[ESCRIBIR]);
    exit(0);
  }

  return 0;
}
