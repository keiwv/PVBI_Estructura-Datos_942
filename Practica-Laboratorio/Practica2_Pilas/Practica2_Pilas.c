/*
    Date created: February 22, 2024 // Last Modified: February 22, 2024

    This program is a practice of the use of stacks in C language.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../teemo.h"

// ************ STRUCTURES ******************
typedef struct Information
{
    char matricula[20];
    char apellido_paterno[50];
    char apellido_materno[50];
    char nombres[100];
} Information;

typedef struct Nodo
{
    Information data;
    struct Nodo *siguiente;
} Nodo;

// ************ PROTOTYPE FUNCTIONS **************
void menu();
int msgeMenu();

void AddNodoEnd(Nodo *head);
void DeleteNodoEnd(Nodo *head);

void freeList(Nodo **head);
Nodo *createList();
Nodo *createNodo();

int main()
{
    menu();
    return 0;
}

// ********** DEVELOPMENT FUNCTIONS *************

void menu()
{
    int op;

    Nodo *head = createList();
    do
    {
        system("clear");
        op = msgeMenu();
        switch (op)
        {
        case 1:
            AddNodoEnd(head);
            break;
        case 2:
            DeleteNodoEnd(head);
            break;
        case 3:
            printf("Mostrar lista\n");
            break;
        case 4:
            printf("Buscar nodo\n");
            break;

        }
    } while (op != 0);
}

int msgeMenu()
{
    printf("1.- Añadir nodo\n");
    printf("2.- Eliminar nodo");
    printf("3.- Mostrar lista\n");
    printf("4.- Buscar nodo\n");
    printf("0.- Salir\n");
    return valid("Selecciona tu opción", 0, 4);
}

void AddNodoEnd(Nodo *head)
{
    Nodo *nuevo = createNodo();
    Nodo *temp = head;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
}

void DeleteNodoEnd(Nodo *head)
{
    Nodo *temp = head;
    Nodo *temp2 = head;
    while (temp->siguiente != NULL)
    {
        temp2 = temp;
        temp = temp->siguiente;
    }
    temp2->siguiente = NULL;
    free(temp);
}






void freeList(Nodo **head)
{
    Nodo *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->siguiente;
        free(temp);
    }
    printf("Lista liberada\n");
    *head = NULL;
}

Nodo *createList()
{
    Nodo *head = (Nodo *)malloc(sizeof(Nodo));
    if (head == NULL)
    {
        printf("No se pudo reservar memoria\n");
        exit(1);
    }
    head->siguiente = NULL;
    return head;
}

Nodo *createNodo()
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (nuevo == NULL)
    {
        printf("No se pudo reservar memoria\n");
        exit(1);
    }
    printf("Matricula: ");
    fflush(stdin);
    fgets(nuevo->data.matricula, sizeof(nuevo->data.matricula), stdin);
    printf("Apellido paterno: ");
    fflush(stdin);
    fgets(nuevo->data.apellido_paterno, sizeof(nuevo->data.apellido_paterno), stdin);
    printf("Apellido materno: ");
    fflush(stdin);
    fgets(nuevo->data.apellido_materno, sizeof(nuevo->data.apellido_materno), stdin);
    printf("Nombres: ");
    fflush(stdin);
    fgets(nuevo->data.nombres, sizeof(nuevo->data.nombres), stdin);
    nuevo->siguiente = NULL;
    return nuevo;
}