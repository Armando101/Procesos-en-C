#include <stdio.h>

int main() {
int a;
int *p;
p=&a;
a=23;
*p=26;
a=7;
printf("Imprime *p");
}
