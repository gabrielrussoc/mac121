#ifndef _HEAP_H
#define _HEAP_H

#include <stdio.h>
#include <stdlib.h>

/* Struct simples que guarda um valor e seu indice
// relativo ao arquivo de entrada */
typedef struct numero {
    int ind, val;
} num;

/* Funcao que recebe um indice (no) e um vetor v[1..m] do tipo num
// e faz v[no] ir para a posicao do vetor que garante a propriedade 
// v[no].val < v[2*no].val e v[no].val < v[2*no+1].val, trocando elementos
// de posicao. Fortemente baseada na do professor Paulo Feofiloff, disponivel em
// http://www.ime.usp.br/~pf/algoritmos/aulas/hpsrt.html */ 
void heapify (int no, int m, num v[]);

/* Funcao que remove v[1] do vetor v[1..n] que e um heap. 
// Chama heapify para garantir que o vetor alterado ainda seja um heap.
// Devolve o novo tamanho do vetor = n - 1. */
int delete (int n, num v[]);

/* Recebe o arquivo file e o vetor v[1..n] que e um heap. Caso o arquivo 
// file ainda nao tenha sido lido complemtamente, substitui a raiz pelo
// proximo valor do arquivo file e retorna 1. Caso contrario, retorna 0. */
int get_new (FILE *file, int n, num v[]);

/* Recebe um vetor de arquivos entrada[0..n-1] e um arquivo saida. Coloca no
// vetor pq[1..n] do tipo num um numero de cada arquivo de entrada (que por sua vez 
// contem numeros em ordem crescente) e o indice de seu arquivo. 
// Transforma pq[1..n] num heap de minimos e escreve a raiz em saida. Se possivel 
// substitui a raiz por um novo numero do mesmo arquivo da raiz antiga e faz um heap, 
// se nao apenas retira a raiz e se faz um heap, ate que pq[] fique vazio.
// Retorna a quantidade de numeros processados nos arquivos. */
int merge_heap (FILE **entrada, FILE *saida, int n);

#endif
