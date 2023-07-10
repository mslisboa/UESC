/*
Escreva um programa que leia dois inteiros e então determine se o maior é múltiplo do
menor.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int maior, menor, aux;

    printf("Digite dois numeros: ");
    scanf("%d %d", &maior, &menor);

    // Verifica o maior e menor número
    if (maior < menor) {
        aux = maior;
        maior = menor;
        menor = aux;
    }

    // Determina se é multiplo
    if((maior % menor) == 0) printf("%d Eh multiplo de %d\n", maior, menor);
    else printf("%d nao eh multiplo de %d\n", maior, menor);

    return 0;
}
