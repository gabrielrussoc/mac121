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

#include "simple.h"

int merge_simple (FILE **entrada, FILE *saida, int n) {
    int *pq, *fim, i, tot = 0, go = 1, min, mini;
    pq = malloc (n * sizeof (int));
    fim = malloc (n * sizeof (int));
    for (i = 0; i < n; i++) 
        fim[i] = 0;
    for (i = 0; i < n; i++) 
        fscanf (entrada[i], "%d", &pq[i]);
    while (go) {
        go = 0;
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            if (!fim[i] && pq[i] <= min) {
                go = 1;
                min = pq[i];
                mini = i;
            }
        }
        if (go) {
            tot++;
            fprintf (saida, "%d\n", min);
            if (fscanf (entrada[mini], "%d", &pq[mini]) == EOF)
                fim[mini] = 1;
        }
    }
    free (pq);
    free (fim);
    return tot;
}
