#include <stdio.h>
#include <math.h> // Required for power functions 

int main() {
    double x, sum, term;
    int i, n, j;
    long long fact;

    // INPUT: Value of x (in radians) and number of terms [cite: 351, 355, 358, 359]
    printf("Enter value of x (in radians): ");
    scanf("%lf", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);

    sum = 0;

    // Practice loops to calculate the sum of the series [cite: 345, 352]
    for (i = 0; i < n; i++) {
        // Calculate factorial for the current term (odd positions: 1, 3, 5...) [cite: 353, 365]
        fact = 1;
        for (j = 1; j <= (2 * i + 1); j++) {
            fact *= j;
        }

        // Calculate the individual term: (x^power / fact) with alternating signs [cite: 350, 366]
        term = pow(x, 2 * i + 1) / fact;

        if (i % 2 == 0) {
            sum += term; // Add positive terms
        } else {
            sum -= term; // Subtract negative terms for alternating signs [cite: 350, 366]
        }
    }

    // OUTPUT: Display the sum of the sine series [cite: 356, 361]
    printf("Sum of sine series = %lf\n", sum);

    return 0;
}