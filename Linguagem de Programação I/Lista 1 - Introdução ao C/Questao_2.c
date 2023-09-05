/*
Escreva um programa que leia os valores (x,y) de um ponto do plano e
informe no qual quadrante o ponto se encontra. Utilize o menor número de condições possível.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x, y;

    printf("Forneca a posicao x e y do ponto: ");
    scanf("%f %f", &x, &y);

    if((x < 0) && (y > 0)) printf("O ponto se encontra no quadrante 1!\n");
    else if((x < 0) && (y < 0)) printf("O ponto se encontra no quadrante 2!\n");
    else if((x > 0) && (y < 0)) printf("O ponto se encontra no quadrante 3!\n");
    else printf("O ponto se encontra no quadrante 4!\n");

    return 0;
}