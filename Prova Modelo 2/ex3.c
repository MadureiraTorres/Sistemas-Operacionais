#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int valor = 0;
    pid_t pid = fork();

    if(pid < 0){
        perror("erro no fork");
        exit(1);
    }

    if(pid == 0){
        valor = 100;
        printf("Filho: valor = %d\n", valor);
    } else {
        wait(NULL);
        printf("Pai: valor = %d\n", valor);
    }

    return 0;
}