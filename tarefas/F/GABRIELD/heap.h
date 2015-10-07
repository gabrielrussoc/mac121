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

#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>

/* Struct simples que guarda um valor e seu indice
// relativo ao arquivo de entrada */
typedef struct no {
    int ind, val;
} node;

/* Recebe p em 1..m e rearranja o vetor v[1..m] de modo que
// v[p..m] seja um heap. Supoe que v[2*p..m] e v[2*p+1..m] sao heaps (para
// 2*p <= m e 2*p+1 <= m).
// Quase identica a do professor Paulo Feofiloff, disponivel em
// http://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html */ 
void fiwDown (int p, int m, node v[]);

/* Recebe v[1..m] onde v[1..m-1] e um heap. Rearranja v de modo que
// v[1..m] vire um heap */
void fixUp (int m, node v[]);

/* Recebe um heap v[1..n] e remove v[1] (substituindo v[1] com v[n]),
// mantendo v[1..n-1] como um heap. Devolve v[1..n-1]. */
node *delete (int n, node v[]);

/* Recebe um heap v[1..n] e insere o novo elemento new, matendo o v[1..n+1]
// como um heap. Devolve v[1..n+1]. */
node *insert (int n, node v[], node new);

/* Recebe um vetor de arquivos entrada[0..n-1], todos contendo numeros em ordem
// nao-decrescente, e um arquivo saida. Grava em saida todos esses numeros em
// ordem nao-decrescente, mantendo no maximo um numero de cada arquivo por vez,
// por meio de uma fila de prioridades que utiliza heaps. Devolve a quantidade
// total de numeros lidos. */
int merge_heap (FILE **entrada, FILE *saida, int n);

#endif
