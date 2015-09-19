#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"
#include "bb.h"

/* Essa funcao e responsavel pela interacao do programa
// com o usuario. */
void usuario (void);

int main (int argc, char *argv[]) {
    FILE *entrada, *saida;
    double tempo;
    int i;

    entrada = fopen (argv[1], "r");
    saida = fopen (argv[2], "w");

    tempo = constroiDicionario (entrada);
    imprimeDicionario (saida);
    fprintf (saida, "Tempo decorrido na montagem do dicionario: %.3lfs\n", tempo);

    usuario ();

    free (buffer);
    for (i = 0; i < n; i++)
        free (dic[i]);
    free (dic);

    fclose (entrada);
    fclose (saida);

    return EXIT_SUCCESS;
}

void usuario () {
    int i, j, c;
    printf ("> ");
    i = 0;
    while ((c = getc (stdin)) != '\n')
        buffer[i++] = c;
    buffer[i] = '\0';
    while (buffer[0] != '\0') {
        j = buscab (0, n - 1, buffer);
        if (j == -1)
            printf ("( ), (%d, %s)\n", 0, dic[0]);
        else if (j == n - 1)
            printf ("(%d, %s), ( )\n", n - 1, dic[n - 1]);
        else
            printf ("(%d, %s), (%d, %s)\n", j, dic[j], j+1, dic[j+1]);

        printf ("> ");
        i = 0;
        while ((c = getc (stdin)) != '\n')
            buffer[i++] = c;
        buffer[i] = '\0';
    }
}