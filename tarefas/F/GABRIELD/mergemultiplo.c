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
// Data: 2015-10-06
// 
// Este arquivo faz parte da tarefa F
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap.h"
#include "simple.h"

#define DEBUG 1

/* O programa recebe uma quantidade arbritaria de arquivos contendo
// numeros ordenados em cada via linha de comando e um arquivo de saida
// e grava em saida todos os numeros dos arquivos em ordem crescente.
// A flag -h roda o programa com um heap e a -s com um vetor comum. */

/* Funcao que serve apenas para fins de teste. Recebe saida ja gravada e
// ve se a quantidade de numeros em saida esta correta (== tot) e se saida
// esta em ordem nao-decrescente */
void verify (FILE *saida, int tot);

int main (int argc, char **argv) {
    int i, n, tot;
    double start, stop;
    FILE **entrada, *saida;

    n = argc - 3;
    entrada = malloc (n * sizeof (FILE));
    saida = fopen (argv[argc - 1], "r+");

    for (i = 2; i < argc - 1; i++)
        entrada[i - 2] = fopen (argv[i], "r");

    if (argv[1][1] == 'h') {
        start = (double) clock () / CLOCKS_PER_SEC;
        tot = merge_heap (entrada, saida, n);
        stop = (double) clock () / CLOCKS_PER_SEC;
    }
    else {
        start = (double) clock () / CLOCKS_PER_SEC;
        tot = merge_simple (entrada, saida, n);
        stop = (double) clock () / CLOCKS_PER_SEC;
    }

    fflush (saida);

    printf ("Tempo gasto: %.3f\n", stop - start);
    printf ("Quantidade de arquivos de entrada: %d\n", n);
    printf ("Quantidade de numeros: %d\n", tot);

    if (DEBUG) verify (saida, tot);

    for(i = 0; i < n; i++)
        fclose (entrada[i]);
    fclose (saida);
    free (entrada);

    return EXIT_SUCCESS;
}

void verify (FILE *saida, int tot) {
    int a, b, cont = 1, messy = 0;
    rewind (saida);
    fscanf (saida, "%d", &a);
    while (fscanf (saida, "%d", &b) != EOF) {
        if (a > b) messy = 1;
        a = b;
        cont++;
    }
    if (messy) printf ("Saida nao esta em ordem!\n");
    if (cont < tot) printf ("Saida contem menos numeros (%d)!\n", cont);
    else if (cont > tot) printf ("Saida contem mais numeros (%d)!\n", cont);
}
