#include "bubblesort.h"

int bubblesort(int a[], int length) {
	int counter = 0;

	for (int i = 0; i < length - 1; i++) { 
		counter++;
		if (a[i] > a[i+1]) { 
			int tmp = a[i];

			a[i] = a[i+1];
			a[i+1] = tmp;
			i = -1;
		}
	}

	return counter;
}