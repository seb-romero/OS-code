#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
    char cadena[255];
    
   while (cadena != "exit"){
        printf(":| &> ");
        fgets(cadena, sizeof(cadena), stdin);

        cadena[strlen(cadena)] = '\x0';
        printf("comando: ");
        puts(cadena);

        char *p = cadena;
        while(*p != '\0')
        {
            printf("%c\n", *p);
            p++;
        }
    //execvp(cadena[0], cadena);
    }

    return 0;
}
