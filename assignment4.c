#include <stdio.h>

int main() {
    float basic, hra, ta, gross, tax, net;

    
    printf("Enter Basic Salary: ");
    scanf("%f", &basic);

    
    hra = 0.10 * basic;
    ta = 0.05 * basic;

   
    gross = basic + hra + ta;

   
    tax = 0.02 * gross;

    
    net = gross - tax;

    
    printf("\nHRA = %.2f", hra);
    printf("\nTA = %.2f", ta);
    printf("\nGross Salary = %.2f", gross);
    printf("\nProfessional Tax = %.2f", tax);
    printf("\nNet Salary = %.2f\n", net);

    return 0;
}