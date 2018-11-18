//1b275
#include <stdio.h>
int main(void) {
    char a[50] = {'0'};
    char *p = &a[0];
    int ch;
    printf("Enter a message: ");

    while (((ch = getchar()) !=  '\n') && (p < &a[0]+50)) {
        *p = ch;
        p++;
    }
    printf("Reversal is: ");
    for (p = p-1; p >= &a[0]; p--) {
        putchar(*p);
    }    
    printf("\n");
	
    return 0;
}