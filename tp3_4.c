// LIBRARIES ==========
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MAIN ==========

int main(){

    char** vectorOfNames;
    char* buffer;
    int nameQuantity;

    buffer = (char*) malloc(50*sizeof(char));

    do
    {
        printf("Ingrese la cantidad de nombres: ");
        scanf("%d", &nameQuantity);
        fflush(stdin);

    } while (nameQuantity <= 0 || nameQuantity >= 20);

    vectorOfNames = (char**) malloc(nameQuantity*sizeof(char*));

    printf("\nEscribir nombres: ----------\n");

    for (short i = 0; i < nameQuantity; i++)
    {
        printf(" - Escriba el Nombre [%d]: ", i+1);

        gets(buffer);

        vectorOfNames[i] = (char *) malloc((strlen(buffer)+1)*sizeof(char));

        strcpy(vectorOfNames[i],buffer);

    }

    printf("\nImprimir nombres: ----------\n");

    for  (short i = 0; i < nameQuantity; i++)
    {
        puts(vectorOfNames[i]);
    }

    free(buffer);

    for (short i = 0; i < nameQuantity; i++)
    {
        free(vectorOfNames[i]);
    }

    free(vectorOfNames);

    return 0;	
}