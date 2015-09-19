#include <stdio.h>
#include <stdlib.h>
#include "dicionario.h"
#include "bb.h"

void usuario (){
    return;
}

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