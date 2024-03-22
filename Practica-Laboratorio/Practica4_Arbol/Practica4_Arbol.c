#include <stdio.h>
#include <stdlib.h>
#include "trees.h"

int main()
{
    int datos[9] = {14, 22, 46, 68, 53, 73, 82, 23, 26};
    int i, n = 8;
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

    return 0;
}
