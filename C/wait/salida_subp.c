#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include "maxrand.h"

int main(int argc, char* argv[])
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) /* Es el subproceso */
         return maxrand(100); /* Genera un numero aleatorio menor a 100*/
    else if (pid > 0)
    { /* El proceso padre recibe lo retornado por el hijo */
        if (wait(&status) >= 0)
        {
            if (WIFEXITED(status))
            {
                /* El proceso hijo retorna algo o ejecuta exit() */
                printf("El proceso hijo ha retornado %d \n", WEXITSTATUS(status));
            }
        }
    }

    return 0;
}
