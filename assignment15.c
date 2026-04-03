#include <stdio.h>
#include <stdlib.h> // Required for rand() and srand()
#include <time.h>   // Required for time() function

int main() {
    int count, i;

    // INPUT: User enters how many random numbers are to be generated
    printf("Enter how many random numbers you want: ");
    scanf("%d", &count);

    // Using srand() to set the seed value for random number generation
    // time(0) provides the current time to ensure different sequences each run
    srand(time(0));

    printf("Pseudo Random Numbers:\n");

    // Loop to generate and display the specified number of random values
    for (i = 0; i < count; i++) {
        // Generating a random number using the standard library function
        printf("%d ", rand());
    }

    printf("\n");

    return 0;
}