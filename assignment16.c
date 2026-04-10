#include <stdio.h>

int main() {
    int n, i;
    
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    
    printf("Enter integers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    printf("Even numbers are: ");
    for (i = 0; i < n; i++) {
       
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
        }
    }

    
    printf("\nOdd numbers are: ");
    for (i = 0; i < n; i++) {
        
        if (arr[i] % 2 != 0) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
    return 0;
}