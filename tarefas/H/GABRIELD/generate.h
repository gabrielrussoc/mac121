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

#ifndef _GENERATE_H
#define _GENERATE_H

/* Preenche o vetor v[0..n-1] com inteiros aleatorios no intervalo
// [a,b]. */
void fill_int (int *v, int n, int a, int b);

/* Preenche o vetor v[0..n-1] com strings de tamanho w+1, de modo que
// v[i] seja uma string que representa um numero intervalo [10^w , 10^(w+1) - 1],
// para todo i em [0..n-1]. */
void fill_string (char **v, int n, int w);

#endif
