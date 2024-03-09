#include <stdio.h>
#include <stdlib.h>
#include "../teemo.h"

typedef struct _Data
{
    int dato;
} Data;

typedef struct Nodo
{
    Data data;
    struct Nodo *siguiente;
} Nodo;

int msge_menu();

void addNode(Nodo **head, int dato);
int pop(Nodo **head);
void showList(Nodo **head);

Nodo *createNode(int dato);
Nodo *createList();

int main()
{
    Nodo *head = createList();
    int op;
    int dato;
    int c;
    int limite = 0;
    do
    {
        system("clear");
        op = msge_menu();
        switch (op)
        {
        case 1:
            printf("Por favor, ingresa el dato: ");
            scanf("%d", &dato);
            addNode(&head, dato);
            break;
        case 2:
            printf("El dato es: ");
            dato = pop(&head);
            printf("%d\n", dato);
            break;
        case 3:
            showList(&head);
            break;
        }
        while ((c = getchar()) != '\n' && c != EOF) // clear buffer
            ;
        getchar();
    } while (op != 0);

    return 0;
}

int msge_menu()
{
    printf("---- M E N U -----\n");
    printf("1.- Ingresar dato\n");
    printf("2.- Leer dato\n");
    printf("3.- Mostrar cola\n");
    printf("0.- Salir\n");
    return valid("Selecciona tu opción: ", 0, 3);
}

Nodo *createNode(int dato)
{
    Nodo *newNode = (Nodo *)malloc(sizeof(Nodo));

    if (newNode == NULL)
    {
        printf("Missing memory\n");
        exit(1);
    }
    newNode->data.dato = dato;
    newNode->siguiente = NULL;
    return newNode;
}

Nodo *createList()
{
    return NULL;
}

void addNode(Nodo **head, int dato)
{
    Nodo *newNode = createNode(dato);

    if (newNode == NULL)
    {
        printf("El nodo no pudo reservar la memoria\n");
        return;
    }

    newNode->data.dato = dato;
    newNode->siguiente = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        printf("Nodo añadido correctamente\n");
        return;
    }

    Nodo *current = *head;
    while (current->siguiente != NULL)
    {
        current = current->siguiente;
    }

    current->siguiente = newNode;
    printf("Nodo añadido correctamente\n");
}

int pop(Nodo **head)
{
    if (*head == NULL)
    {
        printf("El nodo está vacío\n");
        return 0;
    }

    Nodo *temp = *head;
    int value = temp->data.dato;
    *head = (*head)->siguiente;
    free(temp);
    return value;
}

void showList(Nodo **head)
{
    if (*head == NULL)
    {
        printf("La lista está vacía");
        return;
    }
    else
    {
        Nodo *tempNode = *head;
        int i = 1;
        while (tempNode != NULL)
        {
            printf("%d.- %d\n", i, tempNode->data.dato);
            i++;
            tempNode = tempNode->siguiente;
        }
    }
}