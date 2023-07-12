/*
Faça um programa que peça para o aluno digitar 4 notas e imprima na tela a média deste aluno.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    float nota, soma, resultado;
    int cont = 1;

    for(int i = 0; i < 4; i++){
        printf("Digite a nota %d: ", cont);
        scanf("%f", &nota);

        soma += nota;
        cont++;
    }

    resultado = soma / 4;

    printf("\nA media do aluno foi: %.1f\n", resultado);

    return 0;
}
