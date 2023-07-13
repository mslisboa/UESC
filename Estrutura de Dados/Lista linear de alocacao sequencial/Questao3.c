/*
Dada uma lista não ordenada de alunos implementada com uma TListAlunos: 

Implemente uma função que coloca numa pilha, implementada com uma TPilhaAlunos, os calouros (matriculados em 2022.2) e numa fila os restantes.

Coloque os veteranos de volta na lista original e adicione os calouros de forma que estes sejam colocados no final da 
lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define CAP 10

typedef int bool;

typedef struct {
    int matricula;
} TAluno;

typedef struct {
    TAluno* aluno;
    int tam;
    int cap;
} TListaAlunos;

typedef struct {
    TAluno* aluno;
    int topo;
    int cap;
} TPilhaAlunos;

typedef struct {
    TAluno* aluno;
    int inicio;
    int fim;
    int cap;
} TFilaAlunos;


// Gera uma lista de alunos aleatoriamente
void geraListaAlunos(TListaAlunos* lista)
{
    int semestre, complemento;

    for(int i = 0; i < lista->cap; i++){
        // Gera um número de matricula aleatório
        semestre = 1 + (rand() % 2);
        complemento = (rand() % 10000);

        lista->aluno[i].matricula = (((2022 * 10) + semestre) * 10000) + complemento;
        lista->tam++;
    }
}


// Inicializa a lista de alunos
TListaAlunos* initListaAlunos()
{
    TListaAlunos* lista = malloc(sizeof(TListaAlunos));

    lista->cap = CAP;
    lista->tam = 0;

    lista->aluno = malloc(sizeof(TAluno) * (lista->cap + 1));

    geraListaAlunos(lista);

    return lista;
}


// Inicializa uma pilha
TPilhaAlunos* initPilhaAlunos()
{
    TPilhaAlunos* pilha = malloc(sizeof(TPilhaAlunos));

    pilha->cap = CAP;
    pilha->topo = -1;

    pilha->aluno = malloc(sizeof(TAluno) * pilha->cap);

    return pilha;
}


// Inicializa uma fila
TFilaAlunos* initFilaAlunos()
{
    TFilaAlunos* fila = malloc(sizeof(TFilaAlunos));

    fila->inicio = 0;
    fila->fim = 0;
    fila->cap = CAP;

    fila->aluno = malloc(sizeof(TAluno) * fila->cap);

    return fila;
}

// Separa os alunos entre veteranos(fila) e calouros(pilha)
void separaAlunos(TListaAlunos* lista, TPilhaAlunos* pilha, TFilaAlunos* fila)
{
    for(int i = (lista->tam - 1); i >= 0; i--){
        if(lista->aluno[i].matricula < 202220000){
            fila->aluno[fila->fim % fila->cap] = lista->aluno[i];
            fila->fim++;
        } else {
            pilha->topo++;
            pilha->aluno[pilha->topo] = lista->aluno[i];
        }

        lista->tam--;
    }
}

// Reune novamente os alunos na lista
void uniAlunos(TListaAlunos* lista, TPilhaAlunos* pilha, TFilaAlunos* fila)
{
    
}


// Função principal
int main(void){
    TListaAlunos* lista;
    TFilaAlunos* fila;
    TPilhaAlunos* pilha;

    lista = initListaAlunos();
    fila = initFilaAlunos();
    pilha = initPilhaAlunos();

    // Divide os alunos em pilha e fila
    separaAlunos(lista, pilha, fila);
    
    // Exibe a pilha com os calouros(20222...)
    for(int i = pilha->topo; i >= 0; i--) printf("Matricula pilha: %d\n", pilha->aluno[i].matricula);
    
    int i = fila->inicio % fila->cap;
    printf("\n");

    // Exibe a fila com os veteranos(20221...)
    for(int temp = 0; temp < fila->fim - fila->inicio; temp++) {
        printf("Matricula fila: %d\n", fila->aluno[i].matricula);
        i = (i + 1) % fila->cap;
    }

    //for (int i = 0; i < lista->tam; i++) printf("Matricula aluno %d: %d\n", i, lista->aluno[i].matricula);
    
    return 0;
}