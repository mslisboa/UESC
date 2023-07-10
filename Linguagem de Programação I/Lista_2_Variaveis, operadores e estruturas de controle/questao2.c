/*
Escreva um programa que leia um número inteiro e imprima ele em representação decimal,
octal e hexadecimal.
*/

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    printf("\nDecimal: %d\nOctal: %o\nHexadecimal: %X\n", num, num, num);

    return 0;
}
