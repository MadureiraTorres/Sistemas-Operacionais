#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

/*
    3 processos A, B e C
    A faz um fork e cria o B
    B faz um fork e cria o C

    cada processo deve exibir: Eu sou o processo XXX, filho de YYY
    XXX: pid do filho
    YYY: pid do pai

    C deve imprimir a resposta antes do B
    B deve imprimir a resposta antes do A
*/

int main(){
    int pid = fork();

    if(pid != 0){
        wait(NULL);
        sleep(2);
        printf("\nEu sou o processo %d, filho de %d\n", getpid(), getppid());
    } else if(pid == 0){
        int pidAux = fork();

        if(pidAux != 0){
            wait(NULL);
            sleep(2);
            printf("\nEu sou o processo %d, filho de %d\n", getpid(), getppid());
        } else if(pidAux == 0){
            printf("\nEu sou o processo %d, filho de %d\n", getpid(), getppid());
        }
    }

    return 0;
}