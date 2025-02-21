#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>

int main(){

    pid_t pid = fork();

    if(pid == -1){
        perror("Error en fork");
        exit(1);
    }

    if(pid){
        printf("Hola yo soy el PADRE!");

        // Se espera que el proceso hijo termine
        int status;
        //wait(&status);
        waitpid(pid, &status, 0);

        if(WIFEXITED(status)){
            printf("\nEl proceso hijo [%d] termino con estado: %d\n", pid, status);
        }else{
            printf("Ocurrio un error en el proceso hijo");
        }

        printf("Terminando proceso padre \n");
    }else{
        char *arg_Ptr[4];
        arg_Ptr[0] = "child.c";
        arg_Ptr[1] = " Hola :)";
        arg_Ptr[2] = " Soy el proceso Hijo";
        arg_Ptr[3] = NULL;

        execv("./child.bin", arg_Ptr);
    }
}