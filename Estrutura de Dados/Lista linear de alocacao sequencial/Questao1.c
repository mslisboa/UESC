/*
Utilizando somente operações de empilhar e desempilhar, escreva um programa que:

Crie uma pilha de capacidade LSIZE, utilizando a classe TPilhaAlunos, e preencha ela com alunos gerados de forma aleatória. Pode utilizar a função implementada na lista anterior (geraListaDeAlunos()) para gerar os alunos numa lista e depois empilhar os alunos da lista;

Selecione de forma aleatória um aluno que esteja na pilha, um item da lista gerada com a função geraListaDeAlunos(), por exemplo, e  remova o mesmo da pilha. Ao final da execução da função, a pilha deve ser igual à original, exceto pela ausência do aluno removido removido;

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define LSIZE 5

typedef int bool;

// Armazenando as informações de um aluno
typedef struct {
  int numMatricula; // chave com 9 dígitos (INT_MAX +2147483647)
} TAluno;

// Armazena as informações da pilha
typedef struct {
    TAluno *aluno; // Lista de alunos com capacidade LSIZE
    int topo;
    int capacidade;
    int tam;
} TPilhaAlunos;

// Armazena as informações da lista
typedef struct {
    TAluno *aluno;
    int tam;
    int capacidade;
} TListaAlunos;


// Preenche os campos de dados dos alunos com valores aleatórios
void geraAluno(TAluno* aluno){
    int ano, semestre, complemento;

    // Gera um número de matricula aleatório
    ano = (rand() % 23) + 2000;
    semestre = 1 + (rand() % 2);
    complemento = (rand() % 10000);

    aluno->numMatricula = (((ano * 10) + semestre) * 10000) + complemento;
}


// Inicializa e preenche a lista de alunos
TListaAlunos* initListaAlunos(){
    TListaAlunos* lista = malloc(sizeof(TListaAlunos));

    lista->capacidade = LSIZE;
    lista->tam = 0;

    lista->aluno = malloc(sizeof(TAluno) * lista->capacidade);

    for (int i = 0; i < lista->capacidade; i++){
        geraAluno(&lista->aluno[i]);
    }
    
    return lista;
}


// Inicializa uma pilha
TPilhaAlunos* initPilhaAlunos(){
    TPilhaAlunos* pilha = malloc(sizeof(TPilhaAlunos));

    pilha->topo = -1;
    pilha->capacidade = LSIZE;
    pilha->tam = 0;

    pilha->aluno = malloc(sizeof(TAluno) * pilha->capacidade);

    return pilha;
}


// Empilha os alunos da lista em uma pilha
void empilharAlunos(TPilhaAlunos* pilha, TListaAlunos* lista){
    for(int i = 0; i < lista->capacidade; i++){
        pilha->topo++;
        pilha->tam++;
        pilha->aluno[pilha->topo] = lista->aluno[i];
    }
}


// sorteia um aluno e o retira da pilha
bool empilhaEDesempilha(TPilhaAlunos* pilha, TListaAlunos* lista){
    TPilhaAlunos* pilhaAux = initPilhaAlunos();

    TAluno aluno = lista->aluno[rand() % lista->capacidade];
    printf("\nMatricula sorteada: %d\n", aluno.numMatricula);

    for(int i = pilha->topo; i >= 0; i--){
        if(pilha->aluno[i].numMatricula != aluno.numMatricula){
            pilhaAux->topo++;
            pilhaAux->aluno[pilhaAux->topo] = pilha->aluno[i];
            pilha->topo--;

            
        } else {
            pilha->topo--;

            for(int j = i; j < pilha->tam - 1; j++){
                pilha->topo++;
                pilha->aluno[pilha->topo] = pilhaAux->aluno[pilhaAux->topo];
                pilhaAux->topo--;
            }

            pilha->tam--;
            return TRUE;
        }
    }
}


// Exibe os alunos da pilha
void exibeAlunosPilha(TPilhaAlunos* pilha){
    for(int i = pilha->topo; i >= 0; i--) printf("Matricula: %d\n", pilha->aluno[i]);
}


// Exibe os alunos da lista
void ExibeAlunosLista(TListaAlunos* lista){
    for(int i = 0; i < lista->capacidade; i++){
        printf("Matricula aluno %d: %d\n", i, lista->aluno[i].numMatricula);
    }
}


// Função principal
int main(void){
    
    TPilhaAlunos* pilha;
    TListaAlunos* lista;
    // TAluno aluno;
    // int matricula;
    srand(time(NULL));

    lista = initListaAlunos();
    pilha = initPilhaAlunos();

    empilharAlunos(pilha, lista);

    printf("\nPilha\n");
    exibeAlunosPilha(pilha);

    empilhaEDesempilha(pilha, lista);

    printf("\nPilha\n");
    exibeAlunosPilha(pilha);

    return 0;
}