#include "selectionsort.h"

int selectionsort(int array[],int n) {
    int c, d, pos, swap, count = 0;

    for (c = 0; c < (n - 1); c++) {
        pos = c;
        for (d = c + 1; d < n; d++) {
            count++;
            if (array[pos] > array[d]) {
                pos = d;
            }
        }
        if (pos != c) {
            swap = array[c];
            array[c] = array[pos];
            array[pos] = swap;
        }
    }

    return count;
}