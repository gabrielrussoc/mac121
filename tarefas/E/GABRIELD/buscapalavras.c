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

/* Esse programa le um arquivo que o usuario passa via linha de comando,
// gera um dicionario dic[0..n-1] com todas as palavras distintas num arquivo
// tambem passado pela linha de comando com o tempo decorrido no processo.
// Alem disso, le uma palavra p digitada pelo usuario e informa a ultima palavra
// menor igual a p e a primeira maior que p no dicionario. Acaba quando digita
// a palvra vazia. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dicionario.h"
#include "bb.h"

/* Essa funcao e responsavel pela interacao do programa
// com o usuario. Le a palavra digitada e devolve a primeira
// menor igual e a primeira maior do dicionario. */
void usuario (void);

/* Funcao simples que le a query do usuario e retorna NULL
// quando a palavra inserida for vazia. */
char *leQuery (void);

int main (int argc, char *argv[]) {
    FILE *entrada, *saida;
    double tempo;
    int i;

    entrada = fopen (argv[1], "r");
    saida = fopen (argv[2], "w");

    tempo = constroiDicionario (entrada);
    imprimeDicionario (saida);
    fprintf (saida, "Tempo decorrido na montagem do dicionario: %.3fs\n", tempo);

    usuario ();

    free (buffer);
    for (i = 0; i < n; i++)
        free (dic[i]);
    free (dic);

    fclose (entrada);
    fclose (saida);

    return EXIT_SUCCESS;
}

char *leQuery (void) {
    int i, c;
    char *tmp;
    i = 0;
    printf ("> ");
    while ((c = getc (stdin)) != '\n') {
        buffer[i++] = tolower (c);
        if (i >= B) expandeBuffer ();
    }
    buffer[i] = '\0';
    if (i == 0) return NULL;
    tmp = malloc (strlen (buffer) + 1);
    strcpy (tmp, buffer);
    return tmp;
}

void usuario (void) {
    int j;
    char *query;
    while ((query = leQuery ()) != NULL) {
        j = buscab (0, n - 1, buffer);
        if (j == -1)
            printf ("( ) (%d, %s)\n", 0, dic[0]);
        else if (j == n - 1)
            printf ("(%d, %s) ( )\n", n - 1, dic[n - 1]);
        else
            printf ("(%d, %s) (%d, %s)\n", j, dic[j], j + 1, dic[j + 1]);
        free (query);
    }
}