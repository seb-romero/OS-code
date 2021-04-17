#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <assert.h>
#include "utils.h"

int main(void)
{
    char* argv[256];
    int status;
    pid_t pid;

    while(1){
        printf(":| &> ");
        read_command(argv);
        pid = fork();
        assert (pid>=0);


        if(pid==0){ //HIJO
            execvp(argv[0], argv);
        }
        else{ //PADRE
            /*wait(&estado);
            if(WIFEXITED(estado)==0){
                printf(":^]\n");
            } else{
                printf(":^[\n");
            }*/
                read_command(argv);
                fork();
                wait(&status);
            
        }
    }
    
    return 0;
}
