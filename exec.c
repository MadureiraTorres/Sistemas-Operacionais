#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    int status;
    int pid = fork();

    if(pid > 0){

        wait(&status);
        sleep(2);
        printf("\nEu sou o processo %d, filho de %d\n", getpid(), getppid());

    } else if(pid == 0){

        execl("/bin/ls", "ls", "-a", NULL);
        
    }

    return 0;
}