#include <stdio.h>

void create_magic_square(int n, int magic_square[n][n]) {
	int row = 0;
	int col = (n-1)/2;
	magic_square[row][col] = 1;

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
		magic_square[row][col] = num;
	}
}
void print_magic_square(int n, int magic_square[n][n]) {
	for (int row=0; row<n; row++) {
		for (int col=0; col<n; col++) {
			printf("\t%d", magic_square[row][col]);
		}
		printf("\n");
	}
}
int main() {
	int n;
	printf("This program creates a magic square of a specified size.");
	printf("\nThe size must be an odd number between 1 and 99.");
	printf("\nEnter size of magic square: ");
	scanf("%d", &n);
	
	int a[n][n];
	
	create_magic_square(n, a);
	print_magic_square(n, a);	

	return 0;
}

