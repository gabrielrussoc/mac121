/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: Gabriel de Russo e Carmo
// Numero USP: 9298041
// Sigla: GABRIELD
// Data: 2015-10-12
// 
// Este arquivo faz parte da tarefa G
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define N 40000

/* Esse programa testa a biblioteca ordenacao.h */

/* Verifica se o vetor v[0..n-1] esta em ordem nao-decrescente. */
void test (int *v, int n);

/* Preenche o vetor v[0..n-1] com numeros aleatorios. */
void random_fill (int *v, int n); 

int main () {
    int v[N];

    random_fill (v, N);
    insertion_sort (v, N);
    test (v, N);

    random_fill (v, N);
    merge_sort (v, N);
    test (v, N);
    
    random_fill (v, N);
    quick_sort (v, N);
    test (v, N);
    
    random_fill (v, N);
    heap_sort (v, N);
    test (v, N);

    return EXIT_SUCCESS;
}

void test (int *v, int n) {
    int i;
    for(i = 0; i < N - 1; i++)
        if (v[i] > v[i + 1]) {
            printf("Erro! Vetor não ordenado!\n");
            exit (EXIT_FAILURE);
        }
}

void random_fill (int *v, int n) {
    int i;
    srand (time (NULL));
    for(i = 0; i < n; i++)
        v[i] = rand ();
}
