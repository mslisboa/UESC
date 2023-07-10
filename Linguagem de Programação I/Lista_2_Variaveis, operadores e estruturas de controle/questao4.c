/*
Escreva um programa que leia um número inteiro e informe se ele é par ou ímpar.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;

    printf("Insira um numero: ");
    scanf("%d", &num);

    if((num % 2) == 0) printf("\nEsse numero eh par!\n");
    else printf("\nEsse numero eh impar!\n");

    return 0;
}
