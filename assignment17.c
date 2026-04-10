#include <stdio.h>
#include <math.h> 
int main() {
    double x, sum, term;
    int i, n, j;
    long long fact;

    
    printf("Enter value of x (in radians): ");
    scanf("%lf", &x);
    printf("Enter number of terms: ");
    scanf("%d", &n);

    sum = 0;

    
    for (i = 0; i < n; i++) {
       
        fact = 1;
        for (j = 1; j <= (2 * i + 1); j++) {
            fact *= j;
        }

        
        term = pow(x, 2 * i + 1) / fact;

        if (i % 2 == 0) {
            sum += term; 
        } else {
            sum -= term; 
        }
    }

   
    printf("Sum of sine series = %lf\n", sum);

    return 0;
}