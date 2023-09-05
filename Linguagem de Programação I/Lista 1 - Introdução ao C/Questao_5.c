/*
Escreva um programa que leia dois inteiros  e então determine se o maior é múltiplo do menor.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2;

    printf("Digite dois numeros: ");
    scanf("%d %d", &n1, &n2);

    if(n1 > n2){
        if((n1 % n2) == 0) printf("%d eh multiplo de %d", n1, n2);
        else printf("%d nao eh multiplo de %d", n1, n2);
    }
    else{
        if((n2 % n1) == 0) printf("%d eh multiplo de %d", n2, n1);
        else printf("%d nao eh multiplo de %d", n2, n1);
    }

    return 0;
}