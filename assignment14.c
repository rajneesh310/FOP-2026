#include <stdio.h>

int main() {
    int num1, num2, i, smallestCD = -1, gcd;
    int a, b, temp;

    
    printf("Enter Number 1: ");
    scanf("%d", &num1);
    printf("Enter Number 2: ");
    scanf("%d", &num2);

    
    int limit = (num1 < num2) ? num1 : num2;
    for (i = 2; i <= limit; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            smallestCD = i;
            break; 

    
    a = num1;
    b = num2;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    
    printf("\n--- Results ---\n");
    if (smallestCD != -1) {
        printf("Smallest Common Divisor: %d\n", smallestCD);
    } else {
        printf("Smallest Common Divisor: None (other than 1)\n");
    }
    printf("Greatest Common Divisor (GCD): %d\n", gcd);

    return 0;
}