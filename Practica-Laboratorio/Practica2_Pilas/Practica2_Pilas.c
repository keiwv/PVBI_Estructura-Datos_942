/*
    Date created: February 22, 2024 // Last Modified: February 22, 2024

    This program is a practice of the use of stacks in C language.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../teemo.h"

// ************ STRUCTURES ******************
typedef struct Information
{
    int dato;
} Information;

typedef struct Nodo
{
    Information data;
    struct Nodo *siguiente;
} Nodo;

// ************ PROTOTYPE FUNCTIONS **************
Nodo *createStack(int dato);
void pushNode(Nodo *head, int dato);
int popNode(Nodo *head);
bool isEmpty(Nodo *head);
void freeStack(Nodo **head);
int sizeStack(Nodo *head);
void showList(Nodo *head);


Nodo *createNodo();

int main()
{

    Nodo *head = createStack(11);
    
    for (int i = 0; i < 10; i++)
    {
        pushNode(head, i);
    }
    

    printf("Dato desapilado: %d\n", popNode(head));
    
    printf("La pila %s esta vacia\n", isEmpty(head) ? "si" : "no");

    freeStack(&head);

    head = createStack(12);
    for (int i = 0; i < 10; i++)
    {
        pushNode(head, i);
    }
    printf("El tamanio de la pila es: %d\n", sizeStack(head));
    showList(head);

    return 0;
}

// ********** DEVELOPMENT FUNCTIONS *************
Nodo *createNodo(int dato)
{
    Nodo *newNode = (Nodo *)malloc(sizeof(Nodo));
    newNode->data.dato = dato;
    newNode->siguiente = NULL;
    return newNode;

}


Nodo *createStack(int dato)
{
    Nodo *head = (Nodo *)malloc(sizeof(Nodo));
    head->siguiente = NULL;
    head->data.dato = dato;
    printf("Cabeza agregada: %d\n", dato);
    return head;
}

void pushNode(Nodo *head, int dato)
{
    Nodo *newNode = createNodo(dato);
    newNode->data.dato = dato;
    newNode->siguiente = head->siguiente;
    head->siguiente = newNode;
    printf("Dato agregado: %d\n", dato);
}

int popNode(Nodo *head)
{
    if (isEmpty(head))
    {
        return -1;
    }
    Nodo *temp = head->siguiente;
    int dato = temp->data.dato;
    head->siguiente = temp->siguiente;
    free(temp);
    return dato;
}

bool isEmpty(Nodo *head)
{
    return head->siguiente == NULL;
}

void freeStack(Nodo **head)
{
    Nodo *temp;
    while ((*head)->siguiente != NULL)
    {
        temp = (*head)->siguiente;
        (*head)->siguiente = temp->siguiente;
        free(temp);
    }
    free(*head);
    *head = NULL;
    printf("Pila liberada\n");
}

int sizeStack(Nodo *head)
{
    int size = 0;
    Nodo *temp = head;
    while (temp != NULL)
    {
        size++;
        temp = temp->siguiente;
    }
    return size;
}

void showList(Nodo *head)
{
    Nodo *temp = head->siguiente;
    while (temp != NULL)
    {
        printf("%d\n", temp->data.dato);
        temp = temp->siguiente;
    }
}

