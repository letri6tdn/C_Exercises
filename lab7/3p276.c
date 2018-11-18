//3p276

#include <stdio.h>

int main(void) {
    char a[50] = {'0'};
    char *p = a;
    int ch;
    printf("Enter a message: ");
    while (((ch = getchar()) !=  '\n') && (p < a+50)) {
        *p = ch;
        p++;
    }
    printf("Reversal is: ");
    for (p = p-1; p >= a; p--) {
        putchar(*p);
    }    
    printf("\n");
	
    return 0;
}