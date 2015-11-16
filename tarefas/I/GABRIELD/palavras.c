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

#include "palavras.h"

static int B = 0;
static string buffer;
static int L = 1;

/* Aloca o buffer[0..B-1] temporario. */
static void inicializaBuffer (void) {
    B = 16;
    buffer = malloc (B * sizeof (char));
}

/* Desaloca o buffer temporario. */
static void terminaBuffer (void) {
    B = 0;
    free (buffer);
}

/* Dobra o tamanho do buffer. */
static void expandeBuffer (void) {
    string novobuffer;
    int i;
    novobuffer = malloc (2 * B * sizeof (char));
    for (i = 0; i < B; i++)
        novobuffer[i] = buffer[i];
    B *= 2;
    free (buffer);
    buffer = novobuffer;
}

pct *proximaPalavra (FILE *entrada)  {
    int i, c;
    pct *novo;
    string pal;
    if (B == 0) inicializaBuffer ();
    do {
        c = getc (entrada);
        if (c == '\n') L++;
        if (c == EOF) {
            terminaBuffer ();
            return NULL;
        }
    } while (!isalpha (c));
    i = 0;
    do {
        buffer[i++] = tolower (c);
        if (i >= B) expandeBuffer ();
        c = getc (entrada);
    } while (c != EOF && isalnum (c));
    buffer[i] = '\0';
    pal = malloc (strlen (buffer) + 1);
    strcpy (pal, buffer);
    novo = malloc (sizeof (pct));
    novo->pal = pal;
    novo->linha = L;
    if (c == '\n') L++;
    return novo;
}
