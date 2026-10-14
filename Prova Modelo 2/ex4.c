#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int status;
    int pid = fork();

    if(pid != 0){
        wait(&status);

        if(WIFEXITED(status)){
            sleep(2);
            write(1, "\nMini Shell Encerrado\n", sizeof("\nMini Shell Encerrado\n"));
        }
    } else if(pid == 0){
        char aux;
        write(1, "\nMini Shell | Digite 'h' para comandos\n", sizeof("\nMini Shell | Digite 'h' para comandos\n"));

        while(1){
            setbuf(stdin, NULL);
            write(1, "\nmini@shell: ", sizeof("\nmini@shell: "));
            read(0, &aux, 1);

            switch(aux){
                case 'h':
                    write(1, "\n'l' para listar processos\n'm' para mostrar processos\n's' para sair\n", sizeof("\n'l' para listar processos\n'm' para mostrar processos\n's' para sair\n"));
                break;

                case 'l':
                    int pidl = fork();

                    if(pidl == 0){
                        execl("/bin/ls", "ls","-h", NULL);
                        exit(1);
                    }
                break;

                case 'm':
                    int pidm = fork();

                    if(pidm == 0){
                        execl("/bin/ps", "ps aux", "-e", NULL);
                        exit(1);
                    }
                break;

                case 's':
                    exit(0);
                break;
            }

            setbuf(stdin, NULL); 
        }
    }

    return 0;
}