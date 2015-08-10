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
// Data: 2015-08-09
// 
// Este arquivo faz parte da tarefa B (filtro limpa-texto simples)
// da disciplina MAC0121.
// 
///////////////////////////////////////////////////////////////*/

/* Esse programa 'limpa' um dado texto. A limpeza consiste na
eliminacao de caracteres diacriticos, de espacos repetidos e
no tratamento de alguns caracteres de controle. */ 

#include <stdio.h>

/* Essa funcao preenche um vetor que sera usado para a eliminacao
dos caracteres diacriticos. A i-esima posicao guarda o caractere
de valor i na tabela ISO-8859-1 sem o acento diacritico. Posicoes
correspondentes a outros caracteres guardam espaco. */
void ilegal (unsigned char v[256]) {
    int i;
    for (i = 127; i < 256; i++) {
        if (i >= 192 && i <= 197)
            v[i] = 'A';
        else if (i == 199)
            v[i] = 'C';
        else if (i >= 200 && i <= 203)
            v[i] = 'E';
        else if (i >= 204 && i <= 207)
            v[i] = 'I';
        else if (i == 209)
            v[i] = 'N';
        else if (i >= 210 && i <= 214)
            v[i] = 'O';
        else if (i >= 217 && i <= 220)
            v[i] = 'U';
        else if (i == 221)
            v[i] = 'Y';
        else if (i >= 224 && i <= 229)
            v[i] = 'a';
        else if (i == 231)
            v[i] = 'c';
        else if (i >= 232 && i <= 235)
            v[i] = 'e';
        else if (i >= 236 && i <= 239)
            v[i] = 'i';
        else if (i == 241)
            v[i] = 'n';
        else if (i >= 242 && i <= 246)
            v[i] = 'o';
        else if (i >= 249 && i <= 252)
            v[i] = 'u';
        else if (i == 253 || i == 255)
            v[i] = 'y';
        else
            v[i] = ' ';
    }
}

int main () {
    unsigned char c, last, v[256];
    int new;
    new = 1;
    last = 0;
    ilegal (v);
    while (scanf("%c", &c) != EOF) {
        if (c == ' ') {
            if (new == 1)
                printf (" ");
            else
                if (last != ' ')
                    printf (" ");
        }
        else {
            new = 0;
            if (c == '\t')
                printf("       ");
            else if (c == '\n') {
                printf ("\n");
                new = 1;
            }
            else if (c >= 32 && c <= 126)
                printf ("%c", c);
            else if (c >= 127)
                printf ("%c", v[c]);
        }
        last = c;
    }
    if (last != '\n')
        printf ("\n");
    return 0;
}