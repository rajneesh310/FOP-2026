//create structure EMPLOYEE for storing details (name,designation,gender,,date of joining and salary). define function members to compute a) total no. ofnemployees in an organisation b) count of male and female employee c) employee with salary more than 10,000 d) employee with designation "asst mnager"
#include <stdio.h>
#include <string.h>             

struct employee {
    char name[50];
    char designation[50];
    char gender[10];
    char date_of_joining[20];
    float salary;
};              



int main() {
    int n, i;
    int total_employees = 0;
    int male_count = 0;             
    int     female_count = 0;
    int salary_above_10000 = 0;
    int asst_manager_count = 0; 

    printf("Enter number of employees: ");
    scanf("%d", &n);    

    struct employee emp[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Name: ");
        scanf("%s", emp[i].name);

        printf("Designation: ");
        scanf("%s", emp[i].designation);

        printf("
Gender: ");
        scanf("%s", emp[i].gender);
        printf("Date of Joining: ");
        scanf("%s", emp[i].date_of_joining);
        printf("Salary: ");
        scanf("%f", &emp[i].salary);
            
        total_employees++;
        if (strcmp(emp[i].gender, "male") == 0) {   



            male_count++;        } else if (strcmp(emp[i].gender, "female") == 0) { 
                female_count++;
            }
        }
        if (emp[i].salary > 10000) {
            salary_above_10000++;
        }
        if (strcmp(emp[i].designation, "asst manager") == 0) {
            asst_manager_count++;
        }
    }

    printf("\nTotal number of employees: %d\n", total_employees);
    printf("Count of male employees: %d\n", male_count);
    printf("Count of female employees: %d\n", female_count);
    printf("Employees with salary more than 10,000: %d\n", salary_above_10000);
    printf("Employees with designation 'asst manager': %d\n", asst_manager_count);

    return 0;
}   
    