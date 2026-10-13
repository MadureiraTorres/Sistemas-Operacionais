#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
    fazer um programa que liste todos os processos em execução no sistema
*/

int main(){
    int pid = fork();
    
    if(pid == 0){
        execl("/bin/ps", "ps aux", "-e", NULL);
    }

    return 0;
}
