//16p313
//reverse a series number
 
#include <stdio.h>

#define N 50

void reverse(char *message);

int main(void) {
    
    char message[N+1], *p = message;
    char ch;

    printf("Enter message: ");
    while (((ch = getchar()) !=  '\n') && (p < message + N)) {
        *p = ch;
        p++;
    }
    *p = '\0';

    reverse(message);

    printf("Reversal is: %s\n", message);

    return 0;
}

void reverse(char *message) {

    char *p1 = message, *p2;

    while (*message) 
        message++;

    p2 = --message;

    while (p1 < p2) {
        char temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
    return;
}