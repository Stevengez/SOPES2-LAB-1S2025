#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

    printf("\nSoy el proceso HIJO!\n");
    
    printf("Argumento 1: %s\n", argv[1]);
    printf("Argumento 2: %s\n", argv[2]);

    // Simula un proceso que tarda en ejecutarse
    sleep(3);

    printf("Termino la ejecucion del proceso HIJO.\n");
}