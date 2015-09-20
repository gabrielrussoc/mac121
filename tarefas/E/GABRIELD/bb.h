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
// Data: 2015-09-19
// 
// Este arquivo faz parte da tarefa E
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#ifndef BB_H
#define BB_H

/* Essa funcao busca no vetor global dic[0..n-1] a posicao 
// do maior i tal que dic[i] <= pal (lexicograficamente). Caso 
// nao exista tal i, ela devolve -1. */
int buscab (int l, int r, char *pal);

#endif