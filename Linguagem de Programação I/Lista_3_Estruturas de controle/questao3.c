/*
Escreva um programa que leia um número inteiro e imprima ele em representação decimal, octal e hexadecimal.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("Decimal: %d\nOctal: %o\nHexadecimal: %X\n", num, num, num);

    return 0;
}
