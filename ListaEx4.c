#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

/*
Excrever um programa C que cria uma árvore de 3 processos, onde o processo A
faz um fork() criando um processo B, o processo B, por sua vez, faz um fork()
criando um processo C. Cada processo deve exibir uma mensagem 
"Eu sou o processo XXX, filho de YYY", onde XXX e YYY são PIDs de processos. 
Utilizar wait() para garantir que o processo C imprima sua resposta antes 
do B, e que o processo B imprima sua resposta antes do A. Utilizar sleep() 
(man 3 sleep) para haver um intervalo de 1 segundo entre cada mensagem 
impressa.
*/

int main(){
    int status;
    int pidA = fork();

    if(pidA != 0){
        wait(&status);

        printf("\nEu sou o processo A (%d), filho de: %d\n", getpid(), getppid());
        sleep(1);  

    } else if(pidA == 0){
        int pidB = fork();

        if(pidB != 0){
            wait(&status);

            printf("\nEu sou o processo B (%d), filho de A (%d)\n", getpid(), getppid());
            sleep(1);

        } else if(pidB == 0){
            int pidC = fork();

            if(pidC != 0){
                wait(&status);
            } else if(pidC == 0){
                printf("\nEu sou o processo C (%d), filho de B (%d)\n", getpid(), getppid());
                sleep(1);
            }
        }
    }

    return 0;
}
