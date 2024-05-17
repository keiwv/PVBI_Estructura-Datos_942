#include <stdio.h>
#include "trees.h"

int esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int main()
{
    char datos[10] = "1+2*3+1";

     int n = 6;
     Nodo *tree = createNode(datos[0]);
     
    for (int i = 1; i < n; i++)
    {
        insert(tree, datos[i]);
    }
    
    displayPostOrder(tree);

    return 0;
}