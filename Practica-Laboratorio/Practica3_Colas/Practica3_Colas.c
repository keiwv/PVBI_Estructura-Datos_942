#include <stdio.h>
#include <stdlib.h>
#include "../teemo.h"

#define True 1
#define False 0
#define Bool int

typedef struct _Data
{
    int dato;
} Data;
typedef struct Nodo
{
    Data data;
    struct Nodo *siguiente;
} Nodo;
typedef struct head
{
    Nodo *head;
    Nodo *ultimo;
} head;

Nodo *createNode(int dato);
head *createHead(int dato);
void enqueue(head *cabeza, int dato);
void dequeue(head *cabeza);
int getFirstData(head *cabeza);
Bool isEmpty(head *cabeza);
int sizeCola(head *cabeza);
void cleanCola(head *cabeza);
void printQueue(head *cabeza);

int main()
{
    head *queue = createHead(2);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);

    system("clear");

    printQueue(queue);
    printf("\n");

    printf("Primer elemento: %d\n", getFirstData(queue));
    printf("\n");

    printf("Tamanio de la cola: %d\n", sizeCola(queue));
    printf("\n");

    dequeue(queue);
    printf("2 ha sido sacado de la cola\n");
    printQueue(queue);
    printf("\n");

    printf("La cola esta vacia: %s\n", isEmpty(queue) ? "verdadero" : "falso");
    printf("\n");

    cleanCola(queue);
    printf("\n");

    printQueue(queue);
    printf("\n");

    printf("La cola esta vacia: %s\n", isEmpty(queue) ? "verdadero" : "falso");
    printf("\n");

    free(queue);

    return 0;
}

Nodo *createNode(int dato)
{
    Nodo *temp = (Nodo *)malloc(sizeof(Nodo));
    temp->siguiente = NULL;
    temp->data.dato = dato;
    return temp;
}

head *createHead(int dato)
{
    head *newHead = (head *)malloc(sizeof(head));
    newHead->head = createNode(dato);
    newHead->ultimo = newHead->head;
    return newHead;
}

void enqueue(head *cabeza, int dato)
{
    Nodo *nuevoNodo = createNode(dato);

    if (cabeza->ultimo != NULL)
    {
        cabeza->ultimo->siguiente = nuevoNodo;
        cabeza->ultimo = nuevoNodo;
    }
    else
    {
        cabeza->head = nuevoNodo;
        cabeza->ultimo = nuevoNodo;
    }
}

void dequeue(head *cabeza)
{
    if (cabeza->head == NULL)
    {
        printf("Cola está vacía\n");
        return;
    }

    Nodo *temp = cabeza->head;
    cabeza->head = cabeza->head->siguiente;

    if (cabeza->head == NULL)
    {
        cabeza->ultimo = NULL;
    }

    free(temp);
}

int getFirstData(head *cabeza)
{
    return cabeza->head->data.dato;
}

Bool isEmpty(head *cabeza)
{
    if (cabeza->head == NULL && cabeza->ultimo == NULL)
    {
        return True;
    }

    return False;
}

int sizeCola(head *cabeza)
{
    int i = 0;
    Nodo *temp = cabeza->head;
    while (temp != NULL)
    {
        i++;
        temp = temp->siguiente;
    }
    return i;
}

void cleanCola(head *cabeza)
{
    while (cabeza->head != NULL)
    {
        dequeue(cabeza);
    }
    printf("La cola ha sido limpiada exitosamente\n");
}

void printQueue(head *cabeza)
{ 
    printf("Numeros en cola: ");
    if (isEmpty(cabeza))
    {
        printf("la cola esta vacia\n");
        return;
    }
    
    Nodo *actual = cabeza->head;
    while (actual != NULL)
    {
        printf("%d ", actual->data.dato);
        actual = actual->siguiente;
    }
    printf("\n");
}