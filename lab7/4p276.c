//4p276

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char a[50] = {'0'};
    char *p1 = a, *p2 = a;
    int ch;
    printf("Enter a message: ");
    while (((ch = getchar()) !=  '\n') && (p1 < a+50)) {
        if (isalpha(ch)) {
            *p1 = tolower(ch);
            p1++;
        }
    }    
    for (p1 = p1 - 1; p1 >= a; p1--) {
        if (*p1 != *p2) {
            printf("Not a palindrome\n");
            return 0;
        }
        p2++;
    }
    printf("Palindrome\n");

    return 0;
}