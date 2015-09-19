#ifndef BB_H
#define BB_H

/* Essa funcao busca no vetor global dic[0..n-1] a posicao 
// do menor i tal que dic[i] >= pal (lexicograficamente). Caso 
// nao exista tal i, ela devolve n (variavel global que guarda
// o tamanho do vetor dic).*/
int buscab (int l, int r, char *pal);

#endif