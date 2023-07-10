/*
Escreva um programa que leia o raio de um círculo e imprima seu diâmetro, o valor de sua
circunferência e sua área.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.14

int main()
{
    float raio, diametro, circunferencia, area;

    printf("Insira o valor do raio da circunferencia: ");
    scanf("%f", &raio);

    diametro = raio * 2;
    circunferencia = 2 * pi * raio;
    area = pi * (raio * raio);

    printf("Diametro: %.2f\nCircunferencia: %.2f\nArea: %.2f\n", diametro, circunferencia, area);

    // system("pause");

    return 0;
}
