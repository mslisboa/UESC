/*
Faça uma função recursiva que permita inverter um número inteiro N.
Ex: 432 - 234
*/

#include <stdio.h>

void inverte(int n)
{
    if (n == 0) return n;
    else {
        printf("%d", n % 10);
        n /= 10;
        return inverte(n);
    }
}


int main(int argc, char const *argv[])
{
    int numero;
    // int num_invertido;

    scanf("%d", &numero);
    inverte(numero);
    printf("\n");

    return 0;
}
