#include <string.h>
#include <stdio.h>
#include "bb.h"
#include "dicionario.h"

int buscab (int l, int r, char *pal) {
    int mid;
    if (l == r)
        return l + (strcmp (dic[l], pal) < 0);
    mid = (l + r) / 2;
    if (strcmp (dic[mid], pal) >= 0)
        return buscab (l, mid, pal);
    else
        return buscab (mid + 1, r, pal); 
}