#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
programa que executa um loop infinito até que o sinal SIGQUIT
seja recebido.

ao receber o sinal: 
iniciar uma contagem de 2s, depois dela dizer que o programa está sendo encerrado
encerrar com a função exit

fiz com sigint pq meu terminal não tava entendendo o 'ctrl + \', mas a lógica é a mesma
*/

void handler(int sigalrm);
void handler2(int sigint);

int main(){
    signal(SIGALRM, handler);
    signal(SIGINT, handler2);

    while(1){
        pause();
    }
    
    return 0;
}

void handler(int sigalrm){
    (void) sigalrm;

    write(1, "\nSinal de Alarme Recebido, encerrando.\n", sizeof("\nSinal de Alarme Recebido, encerrando...\n"));
    sleep(3);
    exit(0);
}

void handler2(int sigint){
    (void) sigint;
    write(1, "\nSinal de SIGINT Recebido\n", sizeof("\nSinal de SIGINT Recebido\n"));
    write(1, "\nIniciando Contagem...\n", sizeof("\nIniciando Contagem...\n"));
    alarm(2);
}
