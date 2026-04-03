#include <stdio.h>

int main() {
    int num1, num2, i, smallestCD = -1, gcd;
    int a, b, temp;

    // Input: Accept two numbers from the user [cite: 4, 23]
    printf("Enter Number 1: ");
    scanf("%d", &num1);
    printf("Enter Number 2: ");
    scanf("%d", &num2);

    // Part 1: Finding the Smallest Common Divisor (other than 1) [cite: 5, 14]
    // We start from 2 and check each number up to the smaller of the two inputs
    int limit = (num1 < num2) ? num1 : num2;
    for (i = 2; i <= limit; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            smallestCD = i;
            break; // Stop at the first (smallest) common divisor found
        }
    }

    // Part 2: Finding the Greatest Common Divisor (GCD) using Euclidean Algorithm [cite: 6, 16]
    a = num1;
    b = num2;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    gcd = a;

    // Output: Display results 
    printf("\n--- Results ---\n");
    if (smallestCD != -1) {
        printf("Smallest Common Divisor: %d\n", smallestCD);
    } else {
        printf("Smallest Common Divisor: None (other than 1)\n");
    }
    printf("Greatest Common Divisor (GCD): %d\n", gcd);

    return 0;
}