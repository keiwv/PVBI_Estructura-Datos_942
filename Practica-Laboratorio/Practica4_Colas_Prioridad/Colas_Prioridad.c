#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int valor;
    struct nodo *izq;
    struct nodo *der;
} Nodo;

typedef struct {
    Nodo *raiz;
    int tamano;
} Heap;

void Insert(Heap *heap, int value, int prioridad);
Nodo *CreateNode(int value);

int main()
{

    return 0;
}

Nodo *CreateNode(int value)
{
    Nodo *temp = (Nodo*)malloc(sizeof(Nodo));
    if (temp == NULL)
    {
        printf("Error al asignar memoria\n");
        return NULL;
    }
    
    temp->valor = value;
    temp->izq = NULL;
    temp->der = NULL;
    return temp;
}

void Insert(Heap *heap, int value, int prioridad)
{
    Nodo *newNode = CreateNode(value);

    if (newNode == NULL)
    {
        return;
    }

    if (heap == NULL)
    {
        heap->raiz = newNode;
        
    }
    else
    {
        
    }
    


    
}