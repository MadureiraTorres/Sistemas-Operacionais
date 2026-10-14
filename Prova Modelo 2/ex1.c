#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//dar um exemplo de execv

int main(){
    const char *path = "/bin/ps";
    char *argv[] = {"ps aux", NULL};

    int pid = fork();

    if(pid == 0){
        execv(path,argv);
        perror("execv");
        exit(1);
    }

    wait(NULL);

    return 0;
}