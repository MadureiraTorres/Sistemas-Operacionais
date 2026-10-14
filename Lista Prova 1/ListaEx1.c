#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
fazer um programa que dispara a mensagem a cada 10s usando posix
*/

int main(){
    
    char msg[20] = "\nBons estudos!\n";
    
    while(1){
        write(1, msg, 20);
        sleep(10);
    }
    
    return 0;
}
