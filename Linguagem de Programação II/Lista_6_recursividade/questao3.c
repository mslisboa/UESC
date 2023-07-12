/*
Faça uma função recursiva que some os elementos de um vetor de
inteiros.
*/

#include <stdio.h>

int soma(int v[], int tam)
{
    if (tam == 0) return 0;
    else return v[tam - 1] + soma(v, tam - 1);
}


int main(int argc, char const *argv[])
{
    int vetor[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int resultado;

    resultado = soma(vetor, 10);

    printf("= %d\n", resultado);

    return 0;
}
