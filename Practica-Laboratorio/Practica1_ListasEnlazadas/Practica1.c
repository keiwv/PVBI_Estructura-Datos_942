#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "teemo.h"

// Definición de la estructura Nodo
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

void menu();
int menuMsg();

void addNodeMenu();
int addNodeMsg();
void addNodeBegin(Nodo *head);
void addNodePosition(Nodo *head);
void addNodeEnd(Nodo *head);

void showList(Nodo *head);
void searchNode(Nodo *head);
void deleteNode(Nodo *head);
void freeList(Nodo **head);
Nodo *createList();
Nodo *createNodo();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    Nodo *head = createList();
    do
    {
        system("clear");
        op = menuMsg();
        switch (op)
        {
        case 1:
            addNodeMenu(head);
            break;
        case 2:
            showList(head);
            break;
        case 3:
            searchNode(head);
            break;
        case 4:
            deleteNode(head);
            break;
        case 5:
            freeList(&head);
            break;
        }
        if (op != 0)
        {
            printf("Presiona enter para continuar...");
            getchar();
        }

    } while (op != 0);
    freeList(&head);
}

int menuMsg()
{
    printf("1. Agregar\n");
    printf("2. Mostrar\n");
    printf("3. Buscar\n");
    printf("4. Eliminar\n");
    printf("5. Liberar memoria\n");
    printf("0. Salir\n");
    return valid("Selecciona tu opcion: ", 0, 5);
}

void addNodeMenu(Nodo *head)
{
    int op;
    do
    {
        system("clear");
        op = addNodeMsg();
        switch (op)
        {
        case 1:
            addNodeBegin(head);
            break;
        case 2:
            addNodePosition(head);
            break;
        case 3:
            addNodeEnd(head);
        }
        if (op != 0)
        {
            printf("Presiona enter para continuar...");
            getchar();
        }
    } while (op != 0);
}

int addNodeMsg()
{
    printf("1.- Al inicio\n");
    printf("2.- Posicion especifica\n");
    printf("3.- Al final\n");
    printf("0.- Salir\n");
    return valid("Selecciona tu opcion: ", 0, 3);
}

void addNodeBegin(Nodo *head)
{
    Nodo *new = createNodo();
    printf("Matricula: ");
    scanf("%s", new->data.matricula);
    printf("Apellido Paterno: ");
    scanf("%s", new->data.apellido_paterno);
    printf("Apellido Materno: ");
    scanf("%s", new->data.apellido_materno);
    printf("Nombres: ");
    scanf("%s", new->data.nombres);
    new->siguiente = head->siguiente;
    head->siguiente = new;
    printf("Nodo agregado\n");
    getchar();
}

void addNodePosition(Nodo *head)
{
    int pos = valid("Posicion: ", 0, 100);
    Nodo *new = createNodo();
    printf("Matricula: ");
    scanf("%s", new->data.matricula);
    printf("Apellido Paterno: ");
    scanf("%s", new->data.apellido_paterno);
    printf("Apellido Materno: ");
    scanf("%s", new->data.apellido_materno);
    printf("Nombres: ");
    scanf("%s", new->data.nombres);
    Nodo *temp = head;
    for (int i = 0; i < pos; i++)
    {
        if (temp->siguiente == NULL)
        {
            break;
        }
        temp = temp->siguiente;
    }
    new->siguiente = temp->siguiente;
    temp->siguiente = new;
    printf("Nodo agregado\n");
    getchar();
}

void addNodeEnd(Nodo *head)
{
    Nodo *new = createNodo();
    printf("Matricula: ");
    scanf("%s", new->data.matricula);
    printf("Apellido Paterno: ");
    scanf("%s", new->data.apellido_paterno);
    printf("Apellido Materno: ");
    scanf("%s", new->data.apellido_materno);
    printf("Nombres: ");
    scanf("%s", new->data.nombres);
    Nodo *temp = head;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }
    temp->siguiente = new;
    printf("Nodo agregado\n");
    getchar();
}

void showList(Nodo *head)
{
    Nodo *temp = head->siguiente;
    if (temp == NULL)
    {
        printf("Lista vacia\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("------------------------------------\n");
            printf("Matricula: %s\n", temp->data.matricula);
            printf("Apellido Paterno: %s\n", temp->data.apellido_paterno);
            printf("Apellido Materno: %s\n", temp->data.apellido_materno);
            printf("Nombres: %s\n", temp->data.nombres);
            temp = temp->siguiente;
        }
        printf("------------------------------------\n");
    }
}

void searchNode(Nodo *head)
{
    char matricula[20];
    printf("Matricula: ");
    scanf("%s", matricula);
    Nodo *temp = head->siguiente;
    while (temp != NULL)
    {
        if (strcmp(temp->data.matricula, matricula) == 0)
        {
            printf("------------------------------------\n");
            printf("Matricula: %s\n", temp->data.matricula);
            printf("Apellido Paterno: %s\n", temp->data.apellido_paterno);
            printf("Apellido Materno: %s\n", temp->data.apellido_materno);
            printf("Nombres: %s\n", temp->data.nombres);
            printf("------------------------------------\n");
            getchar();
            return;
        }
        temp = temp->siguiente;
    }
    printf("Nodo no encontrado\n");
}

void deleteNode(Nodo *head)
{
    char matricula[20];
    printf("Matricula: ");
    scanf("%s", matricula);
    Nodo *temp = head;
    while (temp->siguiente != NULL)
    {
        if (strcmp(temp->siguiente->data.matricula, matricula) == 0)
        {
            Nodo *aux = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            free(aux);
            printf("Nodo eliminado\n");
            getchar();
            return;
        }
        temp = temp->siguiente;
    }
    printf("Nodo no encontrado\n");
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

Nodo *createNodo()
{
    Nodo *new = (Nodo *)malloc(sizeof(Nodo));
    new->siguiente = NULL;
    return new;
}

Nodo *createList()
{
    Nodo *head = createNodo();
    return head;
}
