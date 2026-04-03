#include <stdio.h>

int main() {
    int num, digit;

    // INPUT: Accept an integer number from the user 
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handling the case where the input number is zero [cite: 70]
    if (num == 0) {
        printf("Digits in reverse order: 0\n");
        return 0;
    }

    // Handling negative numbers by converting to positive 
    if (num < 0) {
        num = -num;
    }

    printf("Digits in reverse order: ");

    // Iterative structure to extract and print digits [cite: 47, 50]
    while (num > 0) {
        // Use modulo (%) to extract the last digit [cite: 45, 68]
        digit = num % 10;
        
        printf("%d ", digit);

        // Use division (/) by 10 to remove the extracted digit [cite: 45, 69]
        num = num / 10;
    }

    printf("\n");

    return 0;
}