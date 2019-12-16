#include "header.h"

void countSort(unsigned char *utensils, int n)
{
    unsigned char count[n], i, j;

    for (i = 0; utensils[i]; i++)
        count[utensils[i]]++;
    j = 0;
    for (i = 0; i < n; i++)
    {
        while (!count[j])
            j++;
        utensils[i] = j;
        count[j]--;
    }
}