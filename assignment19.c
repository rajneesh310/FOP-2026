#include <stdio.h>
#include <string.h>

struct employee {
    char name[50];
    char designation[50];
    char gender;
    char doj[20];   // date of joining
    float salary;
};

// Function to count total employees
void totalEmployees(int n) {
    printf("\nTotal number of employees: %d\n", n);
}

// Function to count male and female employees
void countGender(struct employee e[], int n) {
    int male = 0, female = 0, i;

    for (i = 0; i < n; i++) {
        if (e[i].gender == 'M' || e[i].gender == 'm')
            male++;
        else if (e[i].gender == 'F' || e[i].gender == 'f')
            female++;
    }

    printf("\nMale Employees: %d", male);
    printf("\nFemale Employees: %d\n", female);
}

// Function to display employees with salary > 10000
void highSalary(struct employee e[], int n) {
    int i;
    printf("\nEmployees with salary more than 10000:\n");

    for (i = 0; i < n; i++) {
        if (e[i].salary > 10000) {
            printf("%s\n", e[i].name);
        }
    }
}

// Function to display employees with designation "asst manager"
void asstManager(struct employee e[], int n) {
    int i;
    printf("\nEmployees with designation 'asst manager':\n");

    for (i = 0; i < n; i++) {
        if (strcmp(e[i].designation, "asst manager") == 0) {
            printf("%s\n", e[i].name);
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee e[n];

    // Input employee details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("\nName: ");
        scanf("%s", e[i].name);

        printf("\nDesignation: ");
        scanf("%s", e[i].designation);

        printf("\nGender (M/F): ");
        scanf(" %c", &e[i].gender);

        printf("\nDate of Joining: ");
        scanf("%s", e[i].doj);

        printf("\nSalary: ");
        scanf("%f", &e[i].salary);
    }

    // Function calls
    totalEmployees(n);
    countGender(e, n);
    highSalary(e, n);
    asstManager(e, n);

    return 0;
}
// USING POINTER
#include <stdio.h>
#include <string.h>

struct employee {
    char name[50];
    char designation[50];
    char gender;
    char doj[20];
    float salary;
};

// a) Total employees
void totalEmployees(int n) {
    printf("\nTotal number of employees: %d\n", n);
}

// b) Count male and female employees
void countGender(struct employee *e, int n) {
    int i, male = 0, female = 0;

    for (i = 0; i < n; i++) {
        if ((e + i)->gender == 'M' || (e + i)->gender == 'm')
            male++;
        else if ((e + i)->gender == 'F' || (e + i)->gender == 'f')
            female++;
    }

    printf("\nMale Employees: %d", male);
    printf("\nFemale Employees: %d\n", female);
}

// c) Employees with salary > 10000
void highSalary(struct employee *e, int n) {
    int i;
    printf("\nEmployees with salary more than 10000:\n");

    for (i = 0; i < n; i++) {
        if ((e + i)->salary > 10000) {
            printf("%s\n", (e + i)->name);
        }
    }
}

// d) Employees with designation "asst manager"
void asstManager(struct employee *e, int n) {
    int i;
    printf("\nEmployees with designation 'asst manager':\n");

    for (i = 0; i < n; i++) {
        if (strcmp((e + i)->designation, "asst manager") == 0) {
            printf("%s\n", (e + i)->name);
        }
    }
}

int main() {
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct employee e[n];
    struct employee *ptr = e;   // pointer to structure

    // Input details
    for (i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n", i + 1);

        printf("Name: ");
        scanf("%s", (ptr + i)->name);

        printf("Designation: ");
        scanf(" %[^\n]", (ptr + i)->designation); // for full string

        printf("Gender (M/F): ");
        scanf(" %c", &(ptr + i)->gender);

        printf("Date of Joining: ");
        scanf("%s", (ptr + i)->doj);

        printf("Salary: ");
        scanf("%f", &(ptr + i)->salary);
    }

    // Function calls
    totalEmployees(n);
    countGender(ptr, n);
    highSalary(ptr, n);
    asstManager(ptr, n);

    return 0;
}

