#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    int status;
    int pid = fork();

    if(pid != 0){

        wait(&status);
        printf("\nFatorial de 5: %d\n", WEXITSTATUS(status)*2);

    } else if(pid == 0){

        int pidAux = fork();

        if(pidAux > 0){

            wait(&status);
            exit(WEXITSTATUS(status) * 3);

        } else if(pidAux == 0){

            exit(4*5);

        }
    }

    return 0;
}