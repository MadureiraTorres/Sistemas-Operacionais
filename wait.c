#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    int status;

    if(pid > 0){

        printf("\nProcesso pai esperando o filho acabar\n");
        wait(&status);

        if(WIFEXITED(status)){

            printf("\nProcesso filho encerrou normalmente\n");
            printf("\nValor do status: %d\n", WEXITSTATUS(status));
        
        } else if(WIFSIGNALED(status)){

            printf("\nProcesso filho encerrou por um kill\n");
            printf("\nValor do status: %d\n", WTERMSIG(status));
        
        }

    } else if(pid == 0){
        
        printf("\nCódigo do Filho: %d\n", getpid());
        while(1);
        exit(0);
    
    }

    return 0;
}