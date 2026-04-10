#include <stdio.h>
#include <math.h>


void squareRoot(double n) {
    if (n < 0)
        printf("Square root of negative number is not real.\n");
    else
        printf("Square root of %.2f = %.4f\n", n, sqrt(n));
}


void square(double n) {
    printf("Square of %.2f = %.2f\n", n, n * n);
}

void cube(double n) {
    printf("Cube of %.2f = %.2f\n", n, n * n * n);
}


void checkPrime(int n) {
    if (n < 2) {
        printf("%d is NOT a prime number.\n", n);
        return;
    }
    int isPrime = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            isPrime = 0;
            break;
        }
    }
    if (isPrime)
        printf("%d IS a prime number.\n", n);
    else
        printf("%d is NOT a prime number.\n", n);
}


void factorial(int n) {
    if (n < 0) {
        printf("Factorial of a negative number is undefined.\n");
        return;
    }
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    printf("Factorial of %d = %lld\n", n, fact);
}


void primeFactors(int n) {
    if (n < 2) {
        printf("No prime factors for %d.\n", n);
        return;
    }
    printf("Prime factors of %d: ", n);
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}

int main() {
    double num;
    int choice;

    printf("Enter a number: ");
    scanf("%lf", &num);

    printf("\n--- MENU ---\n");
    printf("1. Square Root\n");
    printf("2. Square\n");
    printf("3. Cube\n");
    printf("4. Check Prime\n");
    printf("5. Factorial\n");
    printf("6. Prime Factors\n");
    printf("Enter your choice (1-6): ");
    scanf("%d", &choice);

    printf("\n");
    switch (choice) {
        case 1: squareRoot(num);         break;
        case 2: square(num);             break;
        case 3: cube(num);               break;
        case 4: checkPrime((int)num);    break;
        case 5: factorial((int)num);     break;
        case 6: primeFactors((int)num);  break;
        default: printf("Invalid choice!\n");
    }

    return 0;
}