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

#ifndef _SIMPLE_H
#define _SIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Recebe um vetor de arquivos entrada[0..n-1], onde entrada[i]
// contem numeros em ordem crescente. Grava em saida todos os numeros 
// em ordem nao-decrescente usando uma fila de prioridade simples, onde
// pq[i] contem o ultimo arquivo nao processado de entrada[i] e fim[i]
// apenas indica se o i-esimo arquivo ja chegou ao fim. Retorna a 
// quantidade de arquivos processados. */
int merge_simple (FILE **entrada, FILE *saida, int n);

#endif
