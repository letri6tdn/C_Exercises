#include <stdio.h>

int main(void) {
    int n,m,r,a,b;
    printf("Enter a fraction: ");
    scanf("%d/%d", &n, &m);
    a = n;
    b = m;
    while (n != 0) {
       r = m % n;
       m = n;
       n = r;
    }
    printf("In lowest terms: %d/%d", (a/m), (b/m));
    
    return 0;
}