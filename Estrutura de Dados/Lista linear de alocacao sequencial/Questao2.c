/*
Escreva um programa que simule o controle de acesso de alunos  à Biblioteca, que tem limitação de
capacidade por conta das restrições da pandemia. Neste programa, o usuário deve ser capaz de realizar
as seguintes tarefas:

Permitir e registrar o acesso dos alunos à Biblioteca de acordo com a capacidade.
Sugestão: Utilizar uma lista com capacidade igual à capacidade da biblioteca, implementada com uma
TListAlunos;

Listar os registros de todos os alunos que estão utilizando a biblioteca no momento;

Caso não tenha capacidade disponível, adicionar novos alunos na fila de espera. Sugestão:
utilizar uma fila de alunos implementada com uma TFilaAlunos;

Listar os registros dos alunos aguardando na fila de espera para acessar à biblioteca; 

Registrar a saída de um aluno da biblioteca e, caso existam alunos na fila, permitir e
registrar o acesso do primeiro da fila de espera;
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define CAP_BIBLIOTECA 10

typedef int bool;

typedef struct{
    int matricula;
} TAluno;

typedef struct{
    TAluno* aluno;
    int tam;
    int capacidade;
} TListaAlunos;

typedef struct
{
    TAluno* aluno;
    int capacidade;
    int inicio;
    int fim;
} TFilaAlunos;


// Inicializa a lista de alunos
TListaAlunos* initListaAluno(){
    int ano, semestre, complemento;
    srand(time(NULL));

    TListaAlunos* lista = malloc(sizeof(TListaAlunos));
    
    // Inicializa os atributos da lista
    lista->capacidade = CAP_BIBLIOTECA;
    lista->tam = 0;

    lista->aluno = malloc(sizeof(TAluno) * (lista->capacidade + 1));

    // Preenche a lista com alunos gerados aleatoriamente
    for(int i = 0; i < lista->capacidade - 1; i++){
        // Gera um número de matricula aleatório
        ano = (rand() % 23) + 2000;
        semestre = 1 + (rand() % 2);
        complemento = (rand() % 10000);

        lista->aluno[i].matricula = (((ano * 10) + semestre) * 10000) + complemento;
        lista->tam++;
    }

    return lista;
}


// Iniciliza a fila de alunos
TFilaAlunos* initFilaAlunos(){
    TFilaAlunos* fila = malloc(sizeof(TFilaAlunos));
    int ano, semestre, complemento;

    // Inicializa os atributos da fila
    fila->capacidade = CAP_BIBLIOTECA;
    fila->inicio = 0;
    fila->fim = 0;

    fila->aluno = malloc(sizeof(TAluno) * CAP_BIBLIOTECA);

    // Preenche a lista com alunos gerados aleatoriamente
    for(int temp = 0; temp < (fila->capacidade - 3); temp++){
        // Gera um número de matricula aleatório
        ano = (rand() % 23) + 2000;
        semestre = 1 + (rand() % 2);
        complemento = (rand() % 10000);

        fila->aluno[fila->fim].matricula = (((ano * 10) + semestre) * 10000) + complemento;
        fila->fim++;
    }

    return fila;
}


// Faz uma busca sentinela pelo aluno na lista
int buscarAlunoLista(TListaAlunos* lista, TAluno registro){
    if(lista->tam == 0) return -1;
    
    lista->aluno[lista->tam] = registro;

    for (int i = 0; i < lista->tam; i++){
        if(lista->aluno[i].matricula == registro.matricula) return i;
    }
}


// Faz uma busca pelo aluno na fila
int buscarAlunoFila(TFilaAlunos* fila, TAluno aluno){
    int i = (fila->inicio % fila->capacidade), temp;

    for(temp = 0; temp < (fila->fim - fila->inicio); temp++){
        if(fila->aluno[i].matricula == aluno.matricula) return i;

        i = (i + 1) % fila->capacidade;
    }

    return (fila->fim % fila->capacidade);
}


// Registra o aluno na lista da biblioteca
bool registrarAlunoLista(TListaAlunos* lista, TAluno aluno){
    if((lista->tam == lista->capacidade) || (buscarAlunoLista(lista, aluno) != lista->tam)) return FALSE;

    lista->aluno[lista->tam] = aluno;
    lista->tam++;

    return TRUE;
}


// Registra o aluno na fila de espera da biblioteca
bool registrarAlunoFila(TFilaAlunos* fila, TAluno aluno){
    if(((fila->fim - fila->inicio) == fila->capacidade) || (buscarAlunoFila(fila, aluno) != fila->fim)) return FALSE;

    fila->aluno[fila->fim % fila->capacidade] = aluno;
    fila->fim++;

    return TRUE;
}


// Exibe os alunos presentes presentes na biblioteca
void listarAlunosLista(TListaAlunos* lista){
    for(int i = 0; i < lista->tam; i++) printf("Matricula aluno %d: %d\n", i, lista->aluno[i].matricula);
}


// Exibe os alunos presentes na fila de espera
void listarAlunosFila(TFilaAlunos* fila){
    int i = fila->inicio % fila->capacidade;

    for(int temp = 0; temp < (fila->fim - fila->inicio); temp++){
        printf("Matricula aluno %d: %d\n", temp, fila->aluno[i].matricula);
        i = (i + 1) % fila->capacidade;
    }
}


// Registra a saida de um aluno da biblioteca
bool registrarSaida(TListaAlunos* lista, TFilaAlunos* fila, TAluno aluno){
    int indiceAluno = buscarAlunoLista(lista, aluno);

    if(indiceAluno == lista->tam) return FALSE;

    lista->aluno[indiceAluno] = lista->aluno[lista->tam - 1];
    lista->tam--;

    if(fila->inicio != fila->fim){
        lista->aluno[lista->tam] = fila->aluno[fila->inicio];
        lista->tam++;
        fila->inicio++;
    }

    return TRUE;
}


// Função principal
int main(void){
    TListaAlunos* lista;
    TFilaAlunos* fila;
    TAluno aluno;
    
    aluno.matricula = 202021764;

    // inicializa a lista de alunos e a fila de espera 
    lista = initListaAluno();
    fila = initFilaAlunos();

    // Inclui um novo aluno a lista
    bool retorno = registrarAlunoLista(lista, aluno);
    printf(": %d\n", retorno);

    // Exibe os alunos presentes na lista e fila de espera
    printf("\nLista\n");
    listarAlunosLista(lista);
    printf("\nFila\n");
    listarAlunosFila(fila);

    // Registra uma saida da biblioteca
    registrarSaida(lista, fila, aluno);

    // Exibe a lista e a fila atualizadas
    printf("\nLista\n");
    listarAlunosLista(lista);
    printf("\nFila\n");
    listarAlunosFila(fila);

    return 0;
}