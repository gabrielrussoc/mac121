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

#ifndef _ABB_H
#define _ABB_H

#include <stdlib.h>
#include "palavras.h"

struct caixa {
    int linha;
    struct caixa *prox;
};
typedef struct caixa cx;

struct no {
    string chave;
    struct no *esq, *dir;
    cx *ini;
};
typedef struct no noh;

typedef noh *arvore;

/* Insere ou atualiza um nó na arvore de busca binária que tem como
// raiz r, de modo que não existam nós com mesma chave nem inteiros
// repetidos em sua lista encadeada. */
arvore insere (arvore r, pct *novo);

/* Devolve a quantidade de nós da arvore de raiz r */
int contaNoh (arvore r);

/* Devolve a altura da arvore de raiz r */
int altura (arvore r);

/* Grava as chaves e suas respectivas listas encadeadas em ordem reversa
// da arvore r na ordem e-r-d em saida */
void imprime (arvore r, FILE *saida);

/* Desaloca todos os nós da arvore com raiz r */
void libera (arvore r);

#endif
