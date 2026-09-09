#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(){
    int pid = fork();

    if(pid != 0){
        wait(NULL);//garante aqui que o filho execute antes que o pai

        printf("\nAqui é processo o pai: %d\n", getpid());
        printf("Criou o filho: %d\n", pid);
    } else if(pid == 0){
        printf("\nAqui é o processo filho: %d; cujo pai é: %d\n", getpid(), getppid());
        printf("Criou: %d\n", pid);
    }

    //pid e retorno da chamada fork são coisas diferentes

    return 0;
}