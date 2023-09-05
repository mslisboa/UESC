/*
Escreva um programa que leia o raio de um círculo e imprima seu diâmetro,
o valor de sua circunferência e sua área.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float r, C, d, a, pi = 3.14;

    printf("Forneca o valor do raio(cm): ");
    scanf("%f", &r);

    d = r * 2;
    C = pi * d;
    a = pi * (r * r); /*pow(r, 2)*/

    printf("Diametro: %.2fcm\nCircunferencia: %.2fcm\nArea: %.2fcm\n", d, C, a);

    return 0;
}