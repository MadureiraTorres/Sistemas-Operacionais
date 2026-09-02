#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sigint);
void handler2(int sigint);

int main(){
    signal(SIGALRM, handler);
    signal(SIGINT, handler2);

    while(1){
        alarm(10);
        pause();
    }

    return 0;
}

void handler(int sigint){
    write(1, "\nSinal de alarme recebido!\n\n",27);
}

void handler2(int sigint){
    write(1, "\nTá tentando me matar?\n\n", 23);

    exit(0);
}