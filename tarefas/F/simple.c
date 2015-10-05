#include "simple.h"

int merge_simple (FILE **entrada, FILE *saida, int n) {
    int *pq, *fim, i, tot = 0, go = 1, min, mini;
    pq = malloc (n * sizeof (int));
    fim = malloc (n * sizeof (int));
    for (i = 0; i < n; i++) 
        fim[i] = 0;
    for (i = 0; i < n; i++) 
        fscanf (entrada[i], "%d", &pq[i]);
    while (go) {
        go = 0;
        min = INT_MAX;
        for (i = 0; i < n; i++) {
            if (!fim[i] && pq[i] <= min) {
                go = 1;
                min = pq[i];
                mini = i;
            }
        }
        if (go) {
            tot++;
            fprintf (saida, "%d\n", min);
            if (fscanf (entrada[mini], "%d", &pq[mini]) == EOF)
                fim[mini] = 1;
        }
    }
    free (pq);
    free (fim);
    return tot;
}
