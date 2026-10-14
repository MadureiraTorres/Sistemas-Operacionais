#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

/*
O status passado como parâmetro à função wait(&status) é, na verdade, 
o mecanismo de retorno de resultado do wait/waitpid. Ao retornar, esta variável 
contém informações sobre o resultado da execução do processo filho. Por exemplo, 
se um processo terminou normalmente (i.e., chamou exit), o comando 
WIFEXITED(status) retorna true. Este comando retorna false se o processo foi 
abortado (e.g., segmentation fault) ou morto (e.g., kill). Investigue no manual 
do wait no Linux (man wait) o funcionamento do comando WEXITSTATUS(status), 
e use-o para modificar o exercício anterior para calcular o 5!, sendo que cada 
processo pode executar apenas uma multiplicação
*/

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
