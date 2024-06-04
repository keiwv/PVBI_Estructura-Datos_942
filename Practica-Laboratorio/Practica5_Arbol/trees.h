#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
int findHeight(Nodo *tree);
int getNumLeaves(Nodo *tree);
bool isComplete(Nodo *tree);
bool isBalanced(Nodo *tree);
Nodo *findMinor(Nodo *tree);
Nodo *deleteNode(Nodo *tree, int dato);
Nodo *findNode(Nodo *tree, int dato);
void modifyNode(Nodo *tree, int oldDato, int newDato);

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

int findHeight(Nodo *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        int left = findHeight(tree->izqPTR);
        int right = findHeight(tree->DerePTR);
        
        return (left > right) ? left + 1 : right + 1;
    }
}

int getNumLeaves(Nodo *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    if (tree->izqPTR == NULL && tree->DerePTR == NULL)
    {
        return 1;
    }

    return getNumLeaves(tree->izqPTR) + getNumLeaves(tree->DerePTR);
}

bool isComplete(Nodo *tree)
{
    if (tree == NULL)
    {
        return true;
    }
    if (tree->izqPTR == NULL && tree->DerePTR == NULL)
    {
        return true;
    }
    if (tree->izqPTR != NULL && tree->DerePTR != NULL)
    {
        return isComplete(tree->izqPTR) && isComplete(tree->DerePTR);
    }
    return false;
}

bool isBalanced(Nodo *tree)
{
    if (tree == NULL)
    {
        return true;
    }

    int leftHeight = findHeight(tree->izqPTR);
    int rightHeight = findHeight(tree->DerePTR);
    
    int difference = leftHeight - rightHeight;

    return (difference >= -1 && difference <= 1) &&
           isBalanced(tree->izqPTR) &&
           isBalanced(tree->DerePTR);
}

Nodo *findMinor(Nodo *tree)
{
    while (tree != NULL && tree->izqPTR != NULL)
    {
        tree = tree->izqPTR;
    }
    return tree;
}

Nodo *deleteNode(Nodo *tree, int dato)
{
    if (tree == NULL)
    {
        return tree;
    }

    if (dato < tree->dato)
    {
        tree->izqPTR = deleteNode(tree->izqPTR, dato);
    }
    else if (dato > tree->dato)
    {
        tree->DerePTR = deleteNode(tree->DerePTR, dato);
    }
    else
    {
        if (tree->izqPTR == NULL)
        {
            Nodo *temp = tree->DerePTR;
            free(tree);
            return temp;
        }
        if (tree->DerePTR == NULL)
        {
            Nodo *temp = tree->izqPTR;
            free(tree);
            return temp;
        }
        Nodo *temp = findMinor(tree->DerePTR);
        tree->dato = temp->dato;
        tree->DerePTR = deleteNode(tree->DerePTR, temp->dato);
    }
    return tree;
}

Nodo *findNode(Nodo *tree, int dato)
{
    if (tree == NULL || tree->dato == dato)
    {
        return tree;
    }
    if (dato < tree->dato)
    {
        return findNode(tree->izqPTR, dato);
    }
    return findNode(tree->DerePTR, dato);
}

void modifyNode(Nodo *tree, int oldDato, int newDato)
{
    Nodo *node = findNode(tree, oldDato);
    if (node != NULL)
    {
        node->dato = newDato;
    }
}
