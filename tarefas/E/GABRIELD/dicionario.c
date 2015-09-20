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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "dicionario.h"
#include "bb.h"

double constroiDicionario (FILE *entrada) {
    double inicio, fim;
    char *pal;
    N = 16;
    dic = malloc (N * sizeof (char *));
    B = 4;
    buffer = malloc (B * sizeof (char));
    n = 0; 
    inicio = (double) clock () / CLOCKS_PER_SEC;
    while ((pal = proximaPalavra (entrada)) != NULL) {
        int i;
        for (i = 0; pal[i] != '\0'; i++) 
            pal[i] = tolower (pal[i]);
        if (!isdigit (pal[0]))
            inserePalavra (pal);
        else
            free (pal);
    }
    fim = (double) clock () / CLOCKS_PER_SEC;
    return fim - inicio;
}

char *proximaPalavra (FILE *entrada)  {
    int i, c;
    char *pal;
    do {
        c = getc (entrada);
        if (c == EOF) return NULL;
    } while (!isalnum (c));
    i = 0;
    do {
        buffer[i++] = c;
        if (i >= B) expandeBuffer ();
        c = getc (entrada);
    } while (c != EOF && isalnum (c));
    buffer[i] = '\0';
    pal = malloc (strlen (buffer) + 1);
    strcpy (pal, buffer);
    return pal;
} 

void expandeBuffer (void) {
    char *novobuffer;
    int i;
    novobuffer = malloc (2 * B * sizeof (char));
    for (i = 0; i < B; i++)
        novobuffer[i] = buffer[i];
    B *= 2;
    free (buffer);
    buffer = novobuffer;
}

void inserePalavra (char *pal) {
    int i, j;
    if (n == 0) 
        dic[n++] = pal;
    else {
        j = buscab (0, n - 1, pal) + 1;
        /* j e a posicao da primeira palavra lexicograficamente maior a pal */
        if (j == 0 || strcmp (dic[j - 1], pal) != 0) {
            if (n == N) 
                expandeDic ();
            for (i = n - 1; i >= j; i--) 
                dic[i + 1] = dic[i];
            dic[j] = pal;
            n++;
        } 
        else 
            free (pal);
    }
} 

void expandeDic (void) {
    char **novodic;
    int i;
    novodic = malloc (2 * N * sizeof (char *));
    for (i = 0; i < N; i++) 
        novodic[i] = dic[i];
    N *= 2;
    free (dic);
    dic = novodic;
}

void imprimeDicionario (FILE *saida) {
    int i;
    for (i = 0; i < n; i++)
        fprintf (saida, "%s\n", dic[i]);  
}
