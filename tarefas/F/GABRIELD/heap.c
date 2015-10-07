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
// Data: 2015-10-04
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include "heap.h"

void fixDown (int p, int m, node v[]) {
    int f = 2 * p;
    node aux;
    while (f <= m) {
        if (f < m && v[f].val > v[f + 1].val) f++;
        if (v[p].val <= v[f].val) break;
        aux = v[p], v[p] = v[f], v[f] = aux;
        p = f, f *= 2;
    }
}

void fixUp (int m, node v[]) {
    node aux;
    while (m > 1) {
        if (v[m / 2].val > v[m].val)
            aux = v[m], v[m] = v[m / 2], v[m / 2] = aux;
        else break;
        m /= 2; 
    }
}

node *delete (int n, node v[]) {
    v[1] = v[n];
    v = realloc (v, n * sizeof (node));
    fixDown (1, n - 1, v);
    return v;
}

node *insert (int n, node v[], node new) {
    v = realloc (v, (n + 2) * sizeof (node));
    v[n + 1] = new; 
    fixUp (n + 1, v);
    return v;
}

int merge_heap (FILE **entrada, FILE *saida, int n) {
    int i, num, tot = 0, tam = 0;
    node *pq, aux;
    pq = NULL;
    for (i = 0; i < n; i++) {
        if (fscanf (entrada[i], "%d", &num) != EOF) {
            aux.val = num, aux.ind = i;
            pq = insert (tam, pq, aux);
            tam++, tot++;
        }
    }
    while (tam > 0) {
        fprintf (saida, "%d\n", pq[1].val);
        i = pq[1].ind;
        pq = delete (tam--, pq);
        if (fscanf (entrada[i], "%d", &num) != EOF) {
            aux.val = num, aux.ind = i;
            pq = insert (tam++, pq, aux);
            tot++;
        }
    }
    free (pq);
    return tot;
}
