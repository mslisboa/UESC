/*
Faça uma função recursiva que calcule e retorne o N-ésimo termo da
sequência Fibonacci. Alguns números desta sequência são: 0, 1, 1, 2, 3,
5, 8, 13, 21, 34, 55, 89...
*/

#include <stdio.h>

int fibonacci(int num)
{
    if (num == 1 || num == 2) return 1;
    else return fibonacci(num - 1) + fibonacci(num - 2);
}


int main(int argc, char const *argv[])
{
    int num, resultado;

    scanf("%d", &num);

    if (num == 1) resultado = 0;
    else resultado = fibonacci(num - 1);

    printf("= %d\n", resultado);

    return 0;
}
