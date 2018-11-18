//17p313

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(const char*message);

int main(void) {
    char a[51] = {'0'};
    char *p1 = a;
    int ch;

    printf("Enter a message: ");

    while (((ch = getchar()) !=  '\n') && (p1 < a + 50)) {
        if (isalpha(ch)) {
            *p1 = tolower(ch);
            p1++;
        }
    }
    *p1 = '\0';
    
    if (is_palindrome(a))
        printf("Palindrome\n");
    else
        printf("Not a palindrome\n");

    return 0;
}

bool is_palindrome(const char *message) {

    for (int i = 0, j = strlen(message) - 1; j >= 0; i++,j--) {
        if (message[i] != message[j]) {
            return false;
        }
    }
    return true;
}