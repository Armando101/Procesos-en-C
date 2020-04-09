#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
int main(){
    pid_t pid;
    pid = fork();
    for (int i = 0; i < 3; ++i){
        printf("%d\n", i);
    }
 
}