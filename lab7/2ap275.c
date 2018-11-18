//2a275

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char a[50] = {'0'};
    int ch, i = 0, j = 0;
    printf("Enter a message: ");
    while (((ch = getchar()) !=  '\n') && (i < 50)) {
        if (isalpha(ch)) {
            a[i] = tolower(ch);
            i++;
        }
    }    
    for (i = i - 1; i >= 0; i--) {
        if (a[i] != a[j]) {
            printf("Not a palindrome\n");
            return 0;
        }
        j++;
    }
    printf("Palindrome\n");

    return 0;
}