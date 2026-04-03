#include <stdio.h>

int main() {
    int choice, i, n;
    float a, b, result = 0;
    int fact = 1;

    printf("\n--- Simple Calculator ---\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power (x^y)\n");
    printf("6. Factorial (x!)\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        case 1:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            result = a + b;
            printf("Result = %.2f\n", result);
            break;

        case 2:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            result = a - b;
            printf("Result = %.2f\n", result);
            break;

        case 3:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            result = a * b;
            printf("Result = %.2f\n", result);
            break;

        case 4:
            printf("Enter two numbers: ");
            scanf("%f %f", &a, &b);
            if (b == 0)
                printf("Error! Division by zero is not allowed.\n");
            else {
                result = a / b;
                printf("Result = %.2f\n", result);
            }
            break;

        case 5:
            printf("Enter base and exponent: ");
            scanf("%f %f", &a, &b);

            result = 1;
            for (i = 1; i <= b; i++) {
                result = result * a;
            }
            printf("Result = %.2f\n", result);
            break;

        case 6:
            printf("Enter a number: ");
            scanf("%d", &n);

            for (i = 1; i <= n; i++) {
                fact = fact * i;
            }
            printf("Factorial = %d\n", fact);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
