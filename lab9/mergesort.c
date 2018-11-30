#include "mergesort.h"

int mergesort(int a[], int left, int right) {
	int count = 0;

	if (left >= right)
		return 0;
	
	int mid = (left + right) / 2;
	mergesort(a, left, mid);
	mergesort(a, mid + 1, right);

	
	for (int i = left; i <= mid; i++)
		for (int j = mid + 1; j <= right; j++) {
			count++;
			if (a[i] > a[j]) { 
				int temp = a[j];
				for (int k = j; k > i; k--){
					a[k] = a[k-1];
				}
				a[i] = temp;
				mid++; 
			}
		}

	return count;
}