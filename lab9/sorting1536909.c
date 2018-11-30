#include <stdio.h>
#include <quicksort.h>
#include <margesort.h>
#include <bubblesort.h>
#include <insertionsort.h>
#include <heapsort.h>
#include <selectionsort.h>
int main(int argc,char *argv[]) {
    int size,i,counter;
    
    printf("Enter the number of integers to be sorted: ");
    scanf("%d", &size);
    
    int a[size];

    if (!strcmp(argv[1],"-q")) {
        counter = quicksort(a,0,size-1);
        printf("Quicksort performs in total %d comparisons;\n", counter);
    }
    
    if (strcmp(argv[1], "-i") == 0) {
        counter = insertionsort(a, size);
        printf("Insertionsort performs in total %d comparisons;\n", counter);
    }

    if (strcmp(argv[1], "-b") == 0) {
        counter = bubblesort(a, size);
        printf("Bubblesort performs in total %d comparisons;\n", counter);
    }    
    
    if (!strcmp(argv[1], "-m")) {
        counter = mergesort(a, 0, size - 1);
        printf("Mergesort performs in total %d comparisons;\n", counter);
    }    

    if (strcmp(argv[1], "-h") == 0) {
        counter = heapsort(a, size);
        printf("Heapsort performs in total %d comparisons;\n", counter);
    }    
    
    if (!strcmp(argv[1], "-s")) {
        counter = selectionsort(a, size);
        printf("Selectionsort performs in total %d comparisons;\n", counter);
        
    }
    
    printf("The sorted order is \"");
    for (i = 0; i < length; i++) {
        printf(" %d", a[i]);
    }
    printf("\".\n");
}
    