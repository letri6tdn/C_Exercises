//program turns positive decimal integer into binary form. 

#include <stdio.h>

void pb(int n) {
    if (n!=0) {
        pb(n/2);
        putchar("0" + n%2);
    }
}

int main()
{
    pb(10);

    return 0;
}
