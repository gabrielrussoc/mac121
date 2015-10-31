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

#include <stdlib.h>
#include "sort.h"

/* Recebe p em 1..m e rearranja o vetor v[1..m] de 
// modo que o "subvetor" cuja raiz e p seja um heap.
// Supoe que os "subvetores" cujas raizes sao filhos
// de p ja sao heaps. */
static void peneira (int p, int m, int *v) { 
    int f = 2 * p, x = v[p];
    while (f <= m) {
        if (f < m && v[f] < v[f+1])  ++f;
        if (x >= v[f]) break;
        v[p] = v[f];
        p = f, f = 2 * p;
    }
    v[p] = x;
}

void heap_sort (int *v, int n) {
    int p, m, x;
    for (p = n / 2; p >= 1; --p)
        peneira (p, n, v);
    for (m = n; m >= 2; --m) {
        x = v[1], v[1] = v[m], v[m] = x;
        peneira (1, m - 1, v);
    }
}

void ordenacaoDigital (char **v, int n, int W) {
    int d, i, r;
    int R = 128;
    int *fp;
    char **aux;
    fp = malloc ((R + 1) * sizeof (int));
    aux = malloc (n * sizeof (char *));

    for (d = W - 1; d >= 0; d--) {
        for (r = 0; r <= R; r++) 
            fp[r] = 0;
        for (i = 0; i < n; i++) 
            fp[v[i][d] + 1] += 1; 
        for (r = 1; r <= R; r++) 
            fp[r] += fp[r - 1]; 
        for (i = 0; i < n; i++) {
            aux[fp[v[i][d]]] = v[i]; 
            fp[v[i][d]]++; 
        }
        for (i = 0; i < n; i++) 
            v[i] = aux[i];
    }

    free (fp);
    free (aux);
}
