#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

/*
-fazer um procedimento que conta o número de vezes que o sinal SIGINT é enviado para o
processo.
-apertar ctrl+c envia o sinal
-quando receber o sinal SIGTSTP com ctrl+z, imprimir no terminal o número de SIGINT recebidos
-depois de receber 3 SIGINT pergunrar se quer sair do programa
-se não responder em 20 segundos forçar saída com SIGALRM
*/

//cabeçalho de funções
void handler(int sigint);
void handler2(int sigtstp);

//variáveis globais
int cont = 0;

int main(){
    signal(SIGINT, handler);
    signal(SIGTSTP, handler2);

    while(1){
        pause();
    }

    return 0;
}

void handler(int sigint){
    (void)sigint;
    cont++;
}

void handler2(int sigtstp){
    (void)sigtstp;

    write(1, "\nNúmero de SIGINT recebidos: ", 30);

    char buffer[10];
    int len = snprintf(buffer, sizeof(buffer), "%d", cont);
    
    write(1, buffer, len);
    write(1, "\n", 1);

    if(cont >= 3){
        write(1, "\nVocê quer sair do programa? (s/n)\n", 36);
        alarm(20);
        pause();
    }
}