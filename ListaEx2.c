#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
fazer um procedimento para contar o número de vezes que um usuário enviou um SIGINT 
para o processo em execução (apertar ctrl + c envia o sinal).
quando o processo receber o SIGTSTP (ctrl + z), imprimir o número de SIGINT recebidos.
depois de 3 SIGINT, perguntar se o usuáruio deseja sair do programa
se o usuário não responder em 20 segundos, SIGALRM deve forçar a saída do programa.
*/

//cabeçalho de funções
void handler(int sigint);
void handler2(int sigtstp);
void handler3(int sigalrm);

//varíaveis globais
int cont = 0;

int main(){
    signal(SIGINT, handler);
    signal(SIGTSTP, handler2);
    signal(SIGALRM, handler3);
    while(1){
        pause(); // O programa ficará em pausa até receber um sinal
    }



    return 0;
}

void handler(int sigint){
    (void) sigint; //ignorar o parâmetro
    cont++;

    if(cont % 3 == 0){
        char resposta[32];
        char pergunta[] = "\nVocê deseja sair do programa? (s/n): ";
        ssize_t n;

        write(1, pergunta, sizeof(pergunta) - 1);
        alarm(20);
        n = read(0, resposta, sizeof(resposta) - 1);

        if (n > 0) {
            resposta[n] = '\0';
            resposta[strcspn(resposta, "\r\n")] = '\0';
        } else {
            resposta[0] = '\0';
        }

        alarm(0);

        if(strcmp(resposta, "s") == 0){
            exit(0);
        } else if(strcmp(resposta, "n") == 0){
            printf("\n%d SIGINT foram recebidos.\n", cont);
            write(1, "\nContinuando o programa...\n", 28);
        } else {
            write(1, "\nResposta inválida. Continuando o programa...\n", 46);
        }
    }
}

void handler2(int sigtstp){
    (void) sigtstp;
    printf("\n%d SIGINT recebidos.\n", cont);
}

void handler3(int sigalrm){
    (void) sigalrm;
    write(1, "\nTempo esgotado! Saindo do programa.\n", 34); 
    printf("\n%d SIGINT foram recebidos.\n", cont);
    sleep(3);
    exit(0);
}
