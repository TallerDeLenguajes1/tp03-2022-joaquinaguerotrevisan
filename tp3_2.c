// LIBRARIES ==========
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CONSTANTS ==========
#define MAX 5

// MAIN ==========

int main(){

    char* vectorNames[MAX];
    char* buffer;
    buffer = (char *) malloc(50*sizeof(char));

    printf("\nEscribir Nombres: ----------\n");

    for (short i = 0; i < MAX; i++)
    {
        printf(" - Escriba el Nombre [%d]: ", i+1);

        gets(buffer);

        vectorNames[i] = (char *) malloc((strlen(buffer)+1)*sizeof(char));

        strcpy(vectorNames[i],buffer);

    }

    printf("\nImprimir Nombres: ----------\n");

    for  (short i = 0; i < MAX; i++)
    {
        puts(vectorNames[i]);
    }

    free(buffer);

    for  (short i = 0; i < MAX; i++)
    {
        free(vectorNames[i]);
    }

    return 0;	
}