/*
Faça um programa que peça para o usuário digitar 2 valores inteiros
e coloque o primeiro valor em uma variável chamada de A e o segundo valor
em outra variável chamada de B. Em seguida, seu programa deverá trocar o
conteúdo destas variáveis e imprimir na tela o que cada variável contém.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int A, B, C;

    printf("Digite os valores de A e B respectivamente: ");
    scanf("%d %d", &A, &B);

    C = A;
    A = B;
    B = C;

    printf("\nAgora os valores estao invertidos:\nA: %d\nB: %d\n", A, B);

    return 0;
}
