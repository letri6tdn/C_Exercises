#include <stdio.h>

int main(void) {
    float loan, interest, rate, payment, month1, month2, month3;
    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interest);
    rate = interest/1200;
    printf("Enter monthly payment: ");
    scanf("%f", &payment);
    
    /*Calculation*/
    
    month1 = loan*(1+rate) - payment;
    printf("Balance remaining after first payment: $%.2f\n", month1);
    month2 = month1*(1+rate) - payment;
    printf("Balance remaining after second payment: $%.2f\n", month2);
    month3 = month2*(1+rate) - payment;
    printf("Balance remaining after third payment: $%.2f\n", month3);
    
    return 0;
}