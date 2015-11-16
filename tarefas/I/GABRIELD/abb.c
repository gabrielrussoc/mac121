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

#include "abb.h"

/* Devolve o maximo entre dois inteiros a e b */
static int max (int a, int b) {
    if (a > b) return a;
    return b;
}

arvore insere (arvore r, pct *novo) {
    noh *filho, *pai, *q;
    cx *p;
    filho = r;
    while (filho != NULL) {
        pai = filho;
        if (strcmp (filho->chave, novo->pal) > 0) filho = filho->esq;
        else if (strcmp (filho->chave, novo->pal) < 0) filho = filho->dir;
        else break;
    }
    if (filho != NULL) {
        if (filho->ini->linha != novo->linha) {
            p = malloc (sizeof (cx));
            p->linha = novo->linha;
            p->prox = filho->ini;
            filho->ini = p;
        }
        free (novo->pal);
    } else {
        q = malloc (sizeof (noh));
        p = malloc (sizeof (cx));
        q->esq = q->dir = NULL;
        q->chave = novo->pal;
        p->linha = novo->linha;
        p->prox = NULL;
        q->ini = p;
        if (r == NULL) return q;
        if (strcmp (pai->chave, q->chave) > 0) pai->esq = q;
        else pai->dir = q;
    }
    return r;
}

int contaNoh (arvore r) {
    if (r == NULL) return 0;
    return 1 + contaNoh (r->esq) + contaNoh (r->dir);
}

int altura (arvore r) {
    if (r == NULL) return -1;
    return 1 + max (altura (r->esq), altura (r->dir));
}

/* Imprime uma lista encadeada de inteiros em ordem reversa */
static void imprimeLista (cx *p, FILE *saida) {
    if (p == NULL) return;
    imprimeLista (p->prox, saida);
    fprintf (saida, " %d", p->linha);
}

void imprime (arvore r, FILE *saida) {
    if (r == NULL) return;
    imprime (r->esq, saida);
    fprintf (saida, "%15s", r->chave);
    imprimeLista (r->ini, saida);
    fprintf (saida, "\n");
    imprime (r->dir, saida);
}

/* Desaloca uma lista encadeada */
static void liberaLista (cx *p) {
    cx *q;
    if (p == NULL) return;
    q = p->prox;
    free (p);
    liberaLista (q);
}

void libera (arvore r) {
    if (r == NULL) return;
    libera (r->esq);
    libera (r->dir);
    liberaLista (r->ini);
    free (r->chave);
    free (r);
}
