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

#ifndef _ORDENACAO_H
#define _ORDENACAO_H

#include <stdlib.h>

/* Rearranja o vetor v[0..n-1] em ordem nao-decrescente em tempo 
// proporcional a n^2 */
void insertion_sort (int *v, int n);

/* Rearranja o vetor v[0..n-1] em ordem nao-decrescente em tempo 
// proporcional a n log n */
void merge_sort (int *v, int n);

/* Rearranja o vetor v[0..n-1] em ordem nao-decrescente em tempo 
// medio proporcional a n log n. No pior caso, roda em tempo
// proporcional a n^2 */
void quick_sort (int *v, int n);

/* Rearranja o vetor v[0..n-1] em ordem nao-decrescente em tempo 
// proporcional a 3 n log n */
void heap_sort (int *v, int n);

#endif
