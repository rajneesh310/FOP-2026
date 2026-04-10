#include <stdio.h>

int main() {
    float m1, m2, m3, m4, m5;
    float total, percentage;

    printf("Enter marks of 5 subjects:\n");
    scanf("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);

    
    if (m1 < 40 || m2 < 40 || m3 < 40 || m4 < 40 || m5 < 40) {
        printf("\nResult: FAIL\n");
    } 
    else {
        
        total = m1 + m2 + m3 + m4 + m5;
        percentage = total / 5;

        printf("\nTotal Marks = %.2f\n", total);
        printf("Percentage = %.2f%%\n", percentage);
        printf("Result: PASS\n");

        
        if (percentage >= 75) {
            printf("Grade: Distinction\n");
        }
        else if (percentage >= 60) {
            printf("Grade: First Division\n");
        }
        else if (percentage >= 50) {
            printf("Grade: Second Division\n");
        }
        else if (percentage >= 40) {
            printf("Grade: Third Division\n");
        }
    }

    return 0;
}
