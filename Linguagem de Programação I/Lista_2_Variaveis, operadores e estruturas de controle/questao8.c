/*
Elabore um programa que permita a entrada de dois valores, x e y, troque seus valores entre
si e então exiba os novos resultados.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, aux;

    printf("Forneca os valores de x e y respectivamente: ");
    scanf("%d %d", &x, &y);

    aux = x;
    x = y;
    y = aux;

    printf("Agora os valores foram invertidos\nX: %d\nY: %d\n", x, y);

    return 0;
}
