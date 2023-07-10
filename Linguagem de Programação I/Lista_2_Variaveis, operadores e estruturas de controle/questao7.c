/*
Escreva um programa que calcule o quadrado e o cubo dos números do 1 ao 10 e use
tabulações para imprimir o resultado da seguinte forma:
numero quadrado cubo
0         0      0
1 1 1
2 4 8
3 9 27
4 16 64
5 25 125
6 36 216
7 49 343
8 64 512
9 81 729
10 100 1000
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int count = 1, i, countq, countc;

    printf("Numero  Quadrado  Cubo\n");

    for(i = 0; i < 10; i++){
        printf("%d %8d %10d\n", count, countq = (count * count),
        countc = (count * count * count));
        count++;
    }

    return 0;
}
