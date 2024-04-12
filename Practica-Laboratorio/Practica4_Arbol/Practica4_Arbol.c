#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    int datos[3] = {4, 2, 7};
    int i, n = 3;
    Nodo *tree = createNode(datos[0]);

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

    return 0;
}
