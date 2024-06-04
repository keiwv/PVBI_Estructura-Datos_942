#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    int datos[9] = {20,18,17,19,20,23,22,25,30};
    int i, n = 9;
    Nodo *tree = createNode(datos[0]);
    Nodo *temp = findMinor(tree);

    for (i = 1; i < n; i++)
    {
        insert(tree, datos[i]);
    }
    system("clear");

    printf("Preorder: ");
    displayPreOrder(tree);
    printf("\n");

    printf("Innorden: ");
    displayInnOrder(tree);
    printf("\n");

    printf("PostOrden: ");
    displayPostOrder(tree);
    printf("\n");

    printf("Altura del nodo: %d\n", findHeight(tree));
    printf("Numero de hojas: %d\n", getNumLeaves(tree));
    printf("Es completo: %d\n", isComplete(tree));
    printf("Balanceado: %d\n", isBalanced(tree));
    printf("El valor menor es: %d\n", temp->dato);

    // Buscando un nodo específico
    int searchValue = 23;
    Nodo *searchResult = findNode(tree, searchValue);
    if (searchResult != NULL)
    {
        printf("Nodo con valor %d encontrado.\n", searchValue);
    }
    else
    {
        printf("Nodo con valor %d no encontrado.\n", searchValue);
    }

    // Modificando un nodo
    int oldDato = 18;
    int newDato = 21;
    modifyNode(tree, oldDato, newDato);
    printf("Nodo con valor %d modificado a %d.\n", oldDato, newDato);

    // Eliminando un nodo
    int deleteValue = 20;
    tree = deleteNode(tree, deleteValue);
    printf("Nodo con valor %d eliminado.\n", deleteValue);

    // Mostrando el árbol nuevamente
    printf("Preorder despues de modificaciones: ");
    displayPreOrder(tree);
    printf("\n");

    printf("Innorden despues de modificaciones: ");
    displayInnOrder(tree);
    printf("\n");

    printf("PostOrden despues de modificaciones: ");
    displayPostOrder(tree);
    printf("\n");

    return 0;
}
