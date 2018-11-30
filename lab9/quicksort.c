#include "quicksort.h"

int count = 0;

int quicksort(int a[], int low, int high) {
    int middle;

    if (low >= high) return 0;
    middle = split(a, low, high, &count);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);

    return count;
}

int split(int a[], int low, int high, int *count) {
    int element = a[low];

    for (;;) {
        while (low < high && element <= a[high]) {
            count[0]++;
            high--;
        }
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= element) {
            count[0]++;
            low++;
        }
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = element;

    return high;
}