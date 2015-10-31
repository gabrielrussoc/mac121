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

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void fill_int (int *v, int n, int a, int b) {
    int i;
    srand (time (NULL));
    for (i = 0; i < n; i++)
        v[i] = rand () % (b - a + 1) + a;
}

void fill_string (char **v, int n, int w) {
    int i, a = 1, b;
    for (i = 0; i < w; i++) a *= 10;
    b = a * 10 - 1;
    srand (time (NULL));
    for (i = 0; i < n; i++)
        sprintf (v[i], "%d", rand () % (b - a + 1) + a);
}
