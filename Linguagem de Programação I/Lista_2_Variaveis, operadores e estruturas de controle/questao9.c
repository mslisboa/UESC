/*
Elabore um programa que receba três valores digitados A, B e C informe se estes podem ser
os lados de um triângulo. O ABC é triângulo se A < B + C e B < A + C e C < A + B.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int A, B, C;

    printf("Informe os valores de A, B, e C respectivamente: ");
    scanf("%d %d %d", &A, &B, &C);

    if((B + C > A) && (A + C > B) && (A + B > C)) printf("\nOs valores fornecidos podem forma um triangulo!\n");
    else printf("\nOs valores fornecidos nao podem formar um triangulo!\n");

    return 0;
}
