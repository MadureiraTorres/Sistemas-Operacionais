#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/*
processo pai: aguardar o término do filho e informar se:
- terminou normalmente (exit)
- terminou por sinal (kill)

processo filho: 
-opção 1: entrar em loop infinito
-opção 2: terminar normalmente (exit)
*/

int main(){
    int status; // obter status para wait()
    int pid = fork(); // criação do processo

    if(pid != 0){
        wait(&status); // espera o processo filho acabar

        if(WIFEXITED(status)){
            write(1, "\nProcesso Filho encerrou normalmente\n", 38); // retorna se encerrou por exit(0)
        
        } else if(WIFSIGNALED(status)){
            write(1, "\nProcesso Filho encerrou por sinal\n", 36); // ou se encerrou por kill no terminal
        }
    
    } else if(pid == 0){
        char aux; //auxiliar que é a opção do menu

        //syscalls de escrita
        write(1, "\nOpção 1: Entrar em Loop\n", sizeof("\nOpção 1: Entrar em Loop\n"));
        write(1, "\nOpção 2: Terminar o Programa Normalmente\n", sizeof("\nOpção 2: Terminar o Programa Normalmente\n"));
        write(1, "\nSua opção: ", sizeof("\nSua opção: "));

        //syscall de leitura
        read(0, &aux, 1);

        if(aux == '1'){
            write(1, "\nLoop Infinito...\n", sizeof("\nLoop Infinito...\n"));
            printf("\nProcesso: %d\n", getpid()); //obtendo o pid para encerrar o processo via kill
            while(1);
            //loop infinito é apenas um while(1) para nunca sair da condição,
        
        } else if(aux == '2'){
            write(1, "\nEncerrando processo\n", sizeof("\nEncerrando processo\n"));
            exit(0); //exit(0) retorna para o pai o WIFEXITED
        } 
    } 

    return 0;
}
