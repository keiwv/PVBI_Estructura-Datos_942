#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    int datos[9] = {20,18,17,19,20,23,22,25,30};
    int i, n = 3;
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
    printf("El valor menor es: %d\n",temp->dato);


    return 0;
}
