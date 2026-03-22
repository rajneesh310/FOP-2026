#include <stdio.h>

int main() {
    float basic, hra, ta, gross, tax, net;

    // Input basic salary
    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    // Calculate HRA (10%) and TA (5%)
    hra = 0.10 * basic;
    ta = 0.05 * basic;

    // Calculate Gross Salary
    gross = basic + hra + ta;

    // Professional Tax (2% of gross salary)
    tax = 0.02 * gross;

    // Net Salary
    net = gross - tax;

    // Output results
    printf("\nHRA = %.2f", hra);
    printf("\nTA = %.2f", ta);
    printf("\nGross Salary = %.2f", gross);
    printf("\nProfessional Tax = %.2f", tax);
    printf("\nNet Salary = %.2f\n", net);

    return 0;
}