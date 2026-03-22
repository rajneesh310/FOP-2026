#include <stdio.h>

int main() {
    int num, i;

    // Input from user
    printf("Enter a number: ");
    scanf("%d", &num);

    // Generate multiplication table
    printf("Multiplication Table of %d:\n", num);

    for(i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}