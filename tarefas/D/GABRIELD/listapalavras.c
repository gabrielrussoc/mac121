/* -*- coding: iso-latin-1-unix; -*- */
/* DECLARO QUE SOU O UNICO AUTOR E RESPONSAVEL POR ESTE PROGRAMA.
// TODAS AS PARTES DO PROGRAMA, EXCETO AS QUE FORAM FORNECIDAS
// PELO PROFESSOR OU COPIADAS DO LIVRO OU DAS BIBLIOTECAS DE
// SEDGEWICK OU ROBERTS, FORAM DESENVOLVIDAS POR MIM.  DECLARO
// TAMBEM QUE SOU RESPONSAVEL POR TODAS AS COPIAS DESTE PROGRAMA
// E QUE NAO DISTRIBUI NEM FACILITEI A DISTRIBUICAO DE COPIAS.
// 
// Autor: GABRIEL DE RUSSO E CARMO
// Numero USP: 9298041
// Sigla: GABRIELD
// Data: 2015-08-30
// 
// Este arquivo faz parte da tarefa D
// da disciplina MAC0121.
// 
////////////////////////////////////////////////////////////// */

/* Esse programa processa um texto de tamanho arbitrario e devolve
// como saida um dicionario em ordem lexicografica das palavras
// nele contidas. OBS: Palavras com hifen nao sao consideradas como
// apenas uma, ao contrario da lingua portuguesa. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef char *string;

typedef struct cel {
    string word;
    struct cel *next;
} cell;

/* Funcao que verifica se a memoria ja estava totalmente ocupada.
// Retirada da pagina do professor Paulo Feofiloff: 
// http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html#mallocc */
void *mallocc (size_t nbytes) {
    void *ptr;
    ptr = malloc (nbytes);
    if (ptr == NULL) {
        printf ("Socorro! malloc devolveu NULL!\n");
        exit (EXIT_FAILURE);
    }
    return ptr;
}

/* Essa funcao le uma linha da entrada e devolve-a numa string.
// Retirada da pagina do professor Paulo Feofiloff:
// http://www.ime.usp.br/~pf/algoritmos/aulas/io2.html#resizing
// Com uma pequena adaptacao de guardar o caractere '\n' */
string read_line () {
    string line, nline;
    int n, ch, size;
    n = 0;
    size = 60;
    line = mallocc (size + 2);
    while ((ch = getc (stdin)) != '\n' && ch != EOF) {
        if (n == size) {
            size = size * 2;
            nline = mallocc (size + 2);
            strncpy (nline, line, n);
            free (line);
            line = nline;
        }
        line[n++] = tolower (ch);
    }
    if (n == 0 && ch == EOF) {
        free (line);
        return NULL;
    }
    line[n++] = '\n';
    line[n] = '\0';
    nline = mallocc (n + 1);
    strcpy (nline, line);
    free (line);
    return nline;
}

/* A funcao recebe uma palavra a ser guardada no dicionario, que
// por sua vez e uma lista ligada. Tambem recebe um ponteiro para
// a cabeca da celula. Se a palavra ja constar no dicionario, apenas
// libera a memoria da celula e da palavra que nao serao inseridas
// na lista. */
void archive (string word, cell *first) {
    cell *p, *q, *new;
    new = mallocc (sizeof (cell));
    new->word = word;
    p = first;
    q = first->next;
    while (q != NULL && strcmp (q->word, word) < 0) {
        p = q;
        q = q->next;
    }
    if (q != NULL && strcmp (q->word, word) == 0) {
        free (new);
        free (word);   
    }
    else {
        p->next = new;
        new->next = q;
    }
}

/* Essa funcao recebe uma linha a ser processada e a cabeca
// da lista (dicionario). Toda vez que encontra uma palavra,
// chama a funcao archive que decide se guarda-a ou nao. */
void update_words (string line, cell *first) {
    string word;
    int i, j;
    j = 0;
    for (i = 0; line[i] != '\0'; i++) {
        if (!isalnum (line[i])) {
            if (i - j > 0) {
                word = mallocc (i - j + 1);
                strncpy (word, line + j, i - j);
                word[i - j] = '\0';
                archive (word, first);
            }
            j = i + 1;
        }
    }
    free (line);
}

/* Funcao simples que apenas imprime a lista (dicionario)
// na tela. */
void show (cell *first) {
    cell *p;
    p = first->next;
    while(p != NULL) {
        printf ("%s\n",p->word);
        p = p->next;
    }
}

/* Funcao que limpa a lista ligada */
void clean (cell *first) {
    cell *dead;
    first = first;
    while (first != NULL) {
        dead = first;
        first = first->next;
        free (dead->word);
        free (dead);
    }
}

int main () {
    string line;
    cell *first;
    first = mallocc (sizeof (cell));
    first->word = NULL;
    first->next = NULL;
    while ((line = read_line ()) != NULL)
        update_words (line, first);
    show (first);
    clean (first);
    return EXIT_SUCCESS;
}
