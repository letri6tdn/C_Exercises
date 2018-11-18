//1a275
#include <stdio.h>

int main(void) {
    char a[50] = {'0'};
    int ch, i = 0;
    printf("Enter a message: ");
    while (((ch = getchar()) !=  '\n') && (i < 50)) {
        a[i] = ch;
        i++;
    }
    printf("Reversal is: ");
    for (i = i-1; i >= 0; i--) {
        putchar(a[i]);
    }    
    printf("\n");
	
    return 0;
}