#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo
{
    int dato;
    struct _Nodo *izqPTR;
    struct _Nodo *DerePTR;
} Nodo;

// **** PROTOTYPE FUNTIONS ****
Nodo *createNode(int dato);
void insert(Nodo *tree, int dato);
void displayPostOrder(Nodo *tree);
void displayInnOrder(Nodo *tree);
void displayPreOrder(Nodo *tree);


// **** FUNCTIONS DEVELOPMENTS ****
Nodo *createNode(int dato)
{
    Nodo *newNode = (Nodo *)malloc(sizeof(Nodo));
    newNode->dato = dato;
    newNode->DerePTR = NULL;
    newNode->izqPTR = NULL;
    return newNode;
}

void insert(Nodo *tree, int dato)
{
    if (dato > tree->dato)
    {
        if (tree->DerePTR == NULL)
        {
            tree->DerePTR = createNode(dato);
        }
        else
        {
            insert(tree->DerePTR, dato);
        }
    }
    else
    {
        if (tree->izqPTR == NULL)
        {
            tree->izqPTR = createNode(dato);
        }
        else
        {
            insert(tree->izqPTR, dato);
        }
    }
}

void displayPostOrder(Nodo *tree)
{
    if (tree != NULL)
    {
        displayPostOrder(tree->izqPTR);
        displayPostOrder(tree->DerePTR);
        printf("%d ", tree->dato);
    }
    
}

void displayInnOrder(Nodo *tree)
{
    if (tree != NULL)
    {
        displayInnOrder(tree->izqPTR);
        printf("%d ", tree->dato);
        displayInnOrder(tree->DerePTR);
    }
    
}

void displayPreOrder(Nodo *tree)
{
    if (tree != NULL)
    {
        printf("%d ", tree->dato);
        displayPreOrder(tree->izqPTR);
        displayPreOrder(tree->DerePTR);
    }
}


