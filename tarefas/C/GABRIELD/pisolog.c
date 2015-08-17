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
// Data: 2015-08-17
// 
// Este arquivo faz parte da tarefa C
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* Esse programa recebe dois inteiros B e K e calcula o piso do
// logaritmo na base dois de B^i, onde 1 <= i <= k. Evita o overflow
// aritmetico verificando se a proxima multiplicacao nao ultrapassa
// o limite do int: o maior n que pode ser calculado e MAX_INT/b. */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* A funcao piso_log recebe um inteiro n e calcula o piso do log
// de n na base 2. Faz isso contando quantas vezes o numero pode
// ser divido por 2. */
int piso_log (int n) {
	int ans = 0;
	while (n > 1) {
		/* n <= (b^k)/(2^i), pois eh sempre o piso*/
		n /= 2;
		ans++;
	}
	return ans;
}

int main (int argc, char *argv[]) {
	int b, k, i, num;
	b = num = atoi (argv[1]);
	k = atoi (argv[2]);
	printf("         N | |_lg(N)_|\n\n"); 
	for (i = 0; i < k; i++) {
		printf ("%10d | %5d\n", num, piso_log (num)); 
		if(num >= INT_MAX / b) break;
		num *= b;
	}
	return EXIT_SUCCESS;	
}
