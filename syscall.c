#include <unistd.h>
#include <stdlib.h>

/*
    fazer um programa que receba o nome e o ra de um aluno e imprima na tela
    usar read e write
    ra nao pode ser uma string
*/

int main(){
    char *nome;
    int ra;

    nome = malloc(10 * sizeof(char)); //aloca um vetor do tamanho do nome

    read(0, nome, 10); //syscall de leitura
    write(1, nome, 10); //syscall de escrita

    read(0, &ra, 8); //int tem 4 bytes (ra tem 7 dígitos)
    write(1, &ra, 8); 
    

    return 0;
}