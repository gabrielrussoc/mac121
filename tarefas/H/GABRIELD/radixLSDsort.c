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
// Data: 2015-10-31
// 
// Este arquivo faz parte da tarefa H
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generate.h"
#include "sort.h"

/* Esse programa compara experimentalmente a eficiencia dos
// algoritmos heapsort e LSD radix sort. */

/* Verifica se o vetor v[0..n-1] esta em ordem nao decrescente. */
void test_int (int *v, int n);

/* Verifica se o vetor v[0..n-1] esta em ordem lexicografica. */
void test_string (char **v, int n);

int main () {
    int *v, n, i, N;
    double ini, fim;
    char **x;

    N = 320000;
    v = malloc (N * sizeof (int));
    x = malloc (N * sizeof (char *));
    for (i = 0; i < N; i++) 
        x[i] = malloc (10 * sizeof (char *));

    n = 40000;
    printf ("                  Heap          Radix\n");
    for (i = 0; i < 4; i++) {
        fill_int (v, n, 100000000, 999999999);
        fill_string (x, n, 8);

        printf ("N: %6d", n);

        ini = (double) clock () / CLOCKS_PER_SEC;
        heap_sort (v - 1, n);
        fim = (double) clock () / CLOCKS_PER_SEC;
        printf ("      %.3fs ", fim - ini);
        test_int (v, n);

        ini = (double) clock () / CLOCKS_PER_SEC;
        ordenacaoDigital (x, n, 9);
        fim = (double) clock () / CLOCKS_PER_SEC;
        printf ("  |  %.3fs ", fim - ini);
        test_string (x, n);
        printf ("\n");

        n *= 2;
    }

    free (v);
    for (i = 0; i < N; i++) free (x[i]);
    free (x);

    return EXIT_SUCCESS;  
}

void test_int (int *v, int n) {
    int i;
    for (i = 1; i < n; i++)
        if (v[i - 1] > v[i]) {
            printf ("ERRO!");
            return;
        }
    printf ("OK!");
}

void test_string (char **v, int n) {
    int i;
    for (i = 1; i < n; i++)
        if (strcmp (v[i - 1], v[i]) > 0) {
            printf ("ERRO!");
            return;
        }
    printf ("OK!");
}
