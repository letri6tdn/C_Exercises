#include <stdio.h>

int main(void) {
	int num1, num2;
	printf("Enter x: ");
	scanf("%d", &num1);
	num2 = ((((3*num1+2)*num1-5)*num1-1)*num1+7)*num1-6;
	printf("The result is: %d", num2);
	return 0;
}