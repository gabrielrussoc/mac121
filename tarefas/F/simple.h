#ifndef _SIMPLE_H
#define _SIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Recebe um vetor de arquivos entrada[0..n-1], onde entrada[i]
// contem numeros em ordem crescente. Grava em saida todos os numeros 
// em ordem nao-decrescente usando uma fila de prioridade simples, onde
// pq[i] contem o ultimo arquivo nao processado de entrada[i] e fim[i]
// apenas indica se o i-esimo arquivo ja chegou ao fim. Retorna a 
// quantidade de arquivos processados. */
int merge_simple (FILE **entrada, FILE *saida, int n);

#endif
