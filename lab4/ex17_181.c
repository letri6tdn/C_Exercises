#include <stdio.h>

int main() {
	int n;
	printf("This program creates a magic square of a specified size.");
	printf("\nThe size must be an odd number between 1 and 99.");
	printf("\nEnter size of magic square: ");
	scanf("%d", &n);
	
	int a[n][n];

	int row = 0;
	int col = (n-1)/2;
	a[row][col] = 1;

	for (int num=2; num<=n*n;num++) {
		if ((num-1)%n==0) {
		    row++;
		}
		else {
		    row--;
		    row = (row+n)%n;
		    col++;
		    col%=n;
		}
		a[row][col] = num;
	}
	for (row=0; row<n; row++) {
		for (col=0; col<n; col++) {
			printf("\t%d", a[row][col]);
		}
		printf("\n");
	}

	return 0;
}

