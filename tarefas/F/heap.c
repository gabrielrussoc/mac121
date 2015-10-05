#include "heap.h"

void heapify (int no, int m, num v[]) {
    int f = 2 * no;
    num aux;
    while (f <= m) {
        if (f < m && v[f].val > v[f + 1].val) f++;
        if (v[no].val <= v[f].val) break;
        aux = v[no], v[no] = v[f], v[f] = aux;
        no = f, f *= 2;
    }
}

int delete (int n, num v[]) {
    v[1] = v[n];
    heapify (1, n - 1, v);
    return n - 1;
}

int get_new (FILE *file, int n, num v[]) {
    int aux;
    if (fscanf (file, "%d", &aux) != EOF) {
        v[1].val = aux;
        heapify (1, n, v);
        return 1;
    }
    return 0;
}

int merge_heap (FILE **entrada, FILE *saida, int n) {
    int i, aux, tot = 0;
    num *pq;
    pq = malloc ((n + 1) * sizeof (num));
    for (i = 1; i <= n; i++) {
        fscanf (entrada[i - 1], "%d", &aux);
        pq[i].ind = i - 1;
        pq[i].val = aux;
        tot++;
    }
    for (i = n/2; i > 0; i--)
        heapify (i, n, pq);
    while (n > 0) {
        fprintf (saida, "%d\n", pq[1].val);
        if (!get_new (entrada[pq[1].ind], n, pq))
            n = delete (n, pq);
        else tot++;
    }
    free (pq);
    return tot;
}
