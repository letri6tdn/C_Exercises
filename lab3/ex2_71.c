#include    <stdio.h>

int main(void) {
    int number, i1, i2, i3;
    printf("Enter a three-digit number: ");
    scanf("%d", &number);
    i3 = number%10;
    i2 = ((number-i3)/10)%10;
    i1 = (number-i3-i2*10)/100;
    printf("The reversal is: %d%d%d", i3, i2, i1);
    
    return 0;
}