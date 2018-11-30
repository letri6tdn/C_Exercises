#include "insertionsort.h"

int insertionsort(int a[], int length) {
	int count = 0;

	for (int i = 1; i < length; i++) { 
		for (int j = 0; j < i; j++) {
			count++;
			if (a[i] < a[j]) { 
				int tmp = a[i];
				
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}

	return count;
}