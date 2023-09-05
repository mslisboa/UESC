/*
Escreva um programa que receba a entrada de um número inteiro de 5 dígitos,
separe o número em seus dígitos componentes e os imprima separados uns dos outros por três espaços.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, dig1, dig2, dig3, dig4, dig5;

    printf("Digite um numero de 5 digitos: ");
    scanf("%d", &num);

    dig1 = num % 10;
    num = num/10;
    dig2 = num % 10;
    num = num/10;
    dig3 = num % 10;
    num = num/10;
    dig4 = num % 10;
    num = num/10;
    dig5 = num % 10;

    printf("%d   %d   %d   %d   %d", dig1, dig2, dig3, dig4, dig5);

    return 0;
}