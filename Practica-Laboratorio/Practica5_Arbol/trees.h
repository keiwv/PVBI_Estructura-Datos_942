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
Nodo *findMinor(Nodo *tree);
Nodo *deleteNode(Nodo *tree, int dato);

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
        
        if (left > right)
        {
            return left + 1;
        }
        else
        {
            return right + 1;
        }
        
    }
}

int getNumLeaves(Nodo *tree)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        if (tree->DerePTR == NULL && tree->izqPTR == NULL)
        {
            return 1;
        }
    }

    return getNumLeaves(tree->izqPTR) + getNumLeaves(tree->DerePTR);
}

bool isComplete(Nodo *tree)
{
    if (tree == NULL)
    {
        return true;
    }
    else
    {
        if ((tree->izqPTR == NULL && tree->DerePTR == NULL))
        {
            return true;
        }
        else
        {
            if (tree->izqPTR != NULL && tree->DerePTR != NULL)
            {
                return (isComplete(tree->izqPTR) && isComplete(tree->DerePTR));
            }
            else
            {
                return false;
            }
        }
    }
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

    if (difference == -1 || difference == 0 || difference == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

Nodo *findMinor(Nodo *tree)
{
    while (tree->izqPTR != NULL)
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
            Nodo *temp = createNode(dato);
            temp = tree->DerePTR;
            free(tree);
            return temp;
        }
        else
        {
            if (tree->DerePTR == NULL)
            {
                Nodo *temp = createNode(dato);
                temp = tree->izqPTR;
                free(temp);
                return temp;
            }
            Nodo *temp = findMinor(tree->DerePTR);
            tree->dato = temp->dato;
            tree->DerePTR = deleteNode(tree->DerePTR, temp->dato);
        }
        return tree;
        
    }
    
}

