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

#include <stdlib.h>
#include "ordenacao.h"

/* Esse modulo foi essencialmente retirado das paginas do professor
// Paulo Feofiloff, disponivel na web em:
// http://www.ime.usp.br/~pf/algoritmos/index.html */

/* Ordena o vetor v[0..n-1] em ordem nao-decrescente. */
static void insercao (int n, int *v) {
    int i, j, x;
    for (j = 1; j < n; ++j) {
        x = v[j];
        for (i = j-1; i >= 0 && v[i] > x; --i) 
            v[i+1] = v[i];
        v[i+1] = x;
    }
}

/* A função recebe vetores nao-decrescentes v[p..q-1] e 
// v[q..r-1] e rearranja v[p..r-1] em ordem nao-decrescente. */
static void intercala (int p, int q, int r, int *v) {
    int i, j, k, *w;
    w = malloc ((r - p) * sizeof (int));
    for (i = 0, k = p; k < q; ++i, ++k) w[i] = v[k];
    for (j = r - p - 1, k = q; k < r; --j, ++k) w[j] = v[k];
    i = 0; j = r - p- 1;
    for (k = p; k < r; ++k) {
        if (w[i] <= w[j]) v[k] = w[i++];
        else v[k] = w[j--];
    }
    free (w);
}

/* Rearranja o vetor v[p..r-1] em ordem nao-decrescente. */
static void m_sort (int p, int r, int *v) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        m_sort (p, q, v);
        m_sort (q, r, v);
        intercala (p, q, r, v);
    }
}

/* Recebe vetor v[p..r] com p < r. Rearranja os 
// elementos do vetor e devolve j em p..r tal que 
// v[p..j-1] <= v[j] < v[j+1..r]. */
static int separa (int *v, int p, int r) {
    int c = v[p], i = p + 1, j = r, t;
    while (i <= j) {
        if (v[i] <= c) ++i;
        else if (c < v[j]) --j; 
        else {
            t = v[i], v[i] = v[j], v[j] = t;
            ++i; --j;
        }
    }              
    v[p] = v[j], v[j] = c;
    return j; 
}

/* A função recebe um vetor v[p..r], com p <= r+1,
// e rearranja o vetor em ordem nao-decrescente. */
static void q_sort (int *v, int p, int r) {
    int j;
    while (p < r) {      
        j = separa (v, p, r);    
        if (j - p < r - j) {     
            q_sort (v, p, j-1);
            p = j + 1;            
        } else {                 
            q_sort (v, j+1, r);
            r = j - 1;
        }
    }
}
/* Recebe p em 1..m e rearranja o vetor v[1..m] de 
// modo que o "subvetor" cuja raiz é p seja um heap.
// Supõe que os "subvetores" cujas raízes são filhos
// de p já são heaps. */
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

/* Rearranja os elementos do vetor v[1..n] de modo que fiquem
// em ordem nao-decrescente. */
static void h_sort (int n, int *v) {
    int p, m, x;
    for (p = n / 2; p >= 1; --p)
        peneira (p, n, v);
    for (m = n; m >= 2; --m) {
        x = v[1], v[1] = v[m], v[m] = x;
        peneira (1, m-1, v);
    }
}

void insertion_sort (int *v, int n) {
    insercao (n ,v);
}

void merge_sort (int *v, int n) {
    m_sort (0, n, v);
}

void quick_sort (int *v, int n) {
    q_sort (v, 0, n-1);
}

void heap_sort (int *v, int n) {
    h_sort (n, v-1); 
}
