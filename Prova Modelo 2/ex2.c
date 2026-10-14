#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
Fazer um programa que entra em loop infinito, e ao receber um sinal de kill printar uma mensagem informando o usuário antes de finalizar
*/

int main(){
    const char msg[] = "\nPrograma Encerrado por Kill\n";
    const char msg1[] = "\nLoop infinito. Processo: ";

    int status;
    int pid = fork();

    if(pid != 0){
        wait(&status);

        if(WIFSIGNALED(status)){
            write(1, msg, sizeof(msg));
        }
    }else if(pid == 0){
        write(1, msg1, sizeof(msg1));
        printf("%d\n", getpid());
        while(1);
    }

    return 0;
}