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

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "palavras.h"
#include "abb.h"

/* Esse progama processa um arquivo de texto e gera seu respectivo índice
// remissivo. */

/* Calcula o piso do log2 de n */
int pisoLog2 (int n);

int main (int argc, char **argv) {
    FILE *entrada, *saida;
    pct *novo;
    int n;
    double ini, fim;
    arvore r = NULL;
    entrada = fopen (argv[1], "r");
    saida = fopen (argv[2], "w");
    ini = (double) clock () / CLOCKS_PER_SEC;
    while ((novo = proximaPalavra (entrada)) != NULL) {
        if (strlen (novo->pal) > 2) r = insere (r, novo);
        else free (novo->pal);
        free (novo);
    }
    fim = (double) clock () / CLOCKS_PER_SEC;
    n = contaNoh (r);
    printf ("Tempo gasto na montagem do indice remissivo: %.3f\n", fim - ini);
    printf ("Quantidade n de nós da árvore: %d\n", n);
    printf ("Piso de log2 n: %d\n", pisoLog2 (n));
    printf ("Altura da árvore: %d\n", altura (r));
    imprime (r, saida);
    libera (r);
    fclose (entrada);
    fclose (saida);
    return 0;
}

int pisoLog2 (int n) {
    int res = 1;
    while (n > 2) {
        res++;
        n /= 2;
    }
    return res;
}
