#include <stdio.h>

int main() {
    int n, i;
    
    // INPUT: Number of integers (N) [cite: 296]
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // INPUT: The list of integers [cite: 296]
    printf("Enter integers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // OUTPUT: Displays Even numbers [cite: 297]
    printf("Even numbers are: ");
    for (i = 0; i < n; i++) {
        // A number is even if divisible by 2 [cite: 293]
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }

    // OUTPUT: Displays Odd numbers [cite: 297]
    printf("\nOdd numbers are: ");
    for (i = 0; i < n; i++) {
        // A number is odd if not divisible by 2 [cite: 293]
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}