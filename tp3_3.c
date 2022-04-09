// LIBRARIES =============
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// CONSTANTS =============
#define MAX 5

// STRUCTURES ============

// global variable ----
char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

// sturctures ---
struct Producto {

    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100

} typedef Product;

struct Cliente {

    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Product *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
} typedef Client;

// FUNCTIONS ==========

float costoTotalProducto(Product generico);

// MAIN =============

int main(){

    Client clientData;
    Client* vectorOfClients;
    char* buff;
    short clientQuantity;

    buff = (char*) malloc(50*sizeof(char));
    srand(time(NULL));

    do
    {
        printf("\nIngrese la cantidad de Clientes: ");
        scanf("%d",&clientQuantity);
        fflush(stdin);

    } while (clientQuantity <= 0 || clientQuantity >= 5);

    vectorOfClients = (Client*) malloc(clientQuantity*sizeof(Client));

    for (short i = 0; i < clientQuantity; i++){

        printf("\nIngrese el nombre del cliente[%d]: ", i+1);

        gets(buff);
        vectorOfClients[i].NombreCliente = (char *) malloc((strlen(buff)+1)*sizeof(char));
        strcpy(vectorOfClients[i].NombreCliente, buff);
        fflush(stdin);

        vectorOfClients[i].ClienteID = i;

        vectorOfClients[i].CantidadProductosAPedir = (rand()%(5-1+1)+1);

        vectorOfClients[i].Productos = (Product*) malloc(vectorOfClients[i].CantidadProductosAPedir*sizeof(Product));

        for (short j = 0; j < (vectorOfClients[i].CantidadProductosAPedir); j++)
        {
            vectorOfClients[i].Productos[j].ProductoID = j;

            vectorOfClients[i].Productos[j].Cantidad = (rand()%(10-1+1)+1);

            vectorOfClients[i].Productos[j].TipoProducto = (char*) malloc((strlen(buff)+1)*sizeof(char));
            vectorOfClients[i].Productos[j].TipoProducto = TiposProductos[rand()%(5)];
            fflush(stdin);

            vectorOfClients[i].Productos[j].PrecioUnitario = (rand()%(100-10+1)+1);

        }

    }

    for (short i = 0; i < clientQuantity; i++)
    {
        printf("\nCliente[%d] =================", vectorOfClients[i].ClienteID+1);
        printf("\nCantidad de tipos de productos pedidos: ", vectorOfClients[i].CantidadProductosAPedir);
        
        for (short j = 0; j <  (vectorOfClients[i].CantidadProductosAPedir); j++)
        {
            printf("\n       %d) Producto ID [%d] | Producto cantidad[%d] | Tipo de Producto[%s] = Precio Unitario[$%f]", j+1, vectorOfClients[i].Productos[j].ProductoID, vectorOfClients[i].Productos[j].Cantidad, vectorOfClients[i].Productos[j].TipoProducto, vectorOfClients[i].Productos[j].PrecioUnitario);

            printf("\n          - $%f", costoTotalProducto(vectorOfClients[i].Productos[j]));
        }

        printf("\n");
    }

    return 0;
}

// FUNCTIONS ==========

float costoTotalProducto(Product generico){
    return generico.PrecioUnitario * generico.Cantidad;
}