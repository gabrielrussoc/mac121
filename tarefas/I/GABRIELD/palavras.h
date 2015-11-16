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
// Data: 2015-11-15
//
// Este arquivo faz parte da tarefa I
// da disciplina MAC0121.
//
////////////////////////////////////////////////////////////// */

#ifndef _PALAVRAS_H
#define _PALAVRAS_H

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

typedef char *string;

struct pacote {
    string pal;
    int linha;
};
typedef struct pacote pct;

/* Devolve um ponteiro para um struct que contem uma 'palavra boa' de entrada
// e a linha que aparece em entrada.
// Uma palavra é uma sequência maximal não vazia de caracteres alfanuméricos e
// é dita boa se começa com uma letra.*/
pct *proximaPalavra (FILE *entrada);

#endif
