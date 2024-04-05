#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    int datos[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int i, n = 15;
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

    printf("Altura del nodo: %d\n", findHeight(tree) - 1);
    printf("Numero de hojas: %d\n", getNumLeaves(tree));
    printf("Es completo: %d\n", isComplete(tree));

    return 0;
}
