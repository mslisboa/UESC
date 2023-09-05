/*
Escreva um programa que leia um número inteiro e informe se ele é par ou ímpar.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    if((n % 2) == 0) printf("%d eh par!", n);
    else printf("%d eh impar!", n);

    return 0;
}