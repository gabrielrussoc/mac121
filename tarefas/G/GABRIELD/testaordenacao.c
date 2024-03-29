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

/* Esse programa testa a biblioteca ordenacao.h */

/* Verifica se o vetor v[0..n-1] esta em ordem nao-decrescente. */
void test (int *v, int n);

/* Preenche o vetor v[0..n-1] com numeros aleatorios. */
void random_fill (int *v, int n); 

int main () {
    int n, *v;
    n = 40000;
    v = malloc (n * sizeof (int));

    random_fill (v, n);
    printf ("Insertion..");
    insertion_sort (v, n);
    test (v, n);

    random_fill (v, n);
    printf ("Merge..");
    merge_sort (v, n);
    test (v, n);
    
    random_fill (v, n);
    printf ("Quick..");
    quick_sort (v, n);
    test (v, n);
    
    random_fill (v, n);
    printf ("Heap..");
    heap_sort (v, n);
    test (v, n);

    free (v);

    return EXIT_SUCCESS;
}

void test (int *v, int n) {
    int i;
    for (i = 0; i < n - 1; i++)
        if (v[i] > v[i + 1]) {
            printf ("ERRO!\n");
            return;
        }
    printf ("OK!\n");
}

void random_fill (int *v, int n) {
    int i;
    srand (time (NULL));
    for (i = 0; i < n; i++)
        v[i] = rand ();
}
