/*
Faça um programa que leia pelo teclado um valor, em reais, converta e
imprima o mesmo num valor em dólares. Considere que R$3.75 seja equivalente a US$1.00.
*/

#include <stdio.h>
#include <stdlib.h>

#define dolar 3.75

int main(int argc, char const *argv[])
{
    float real, valor_convertido;

    printf("Digite o valor em reais: ");
    scanf("%f", &real);

    valor_convertido = real / dolar;

    printf("\nDolar = %.2f\nValor fornecido: R$%.2f\nValor convertido: SS$%.2f\n", dolar,  real, valor_convertido);

    return 0;
}
