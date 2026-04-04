#include <stdio.h>
#include <string.h> // Required for built-in string functions [cite: 72]

int main() {
    char str1[100], str2[100], temp[200];
    int choice;

    printf("Enter first string: ");
    scanf("%s", str1); // [cite: 81]
    printf("Enter second string: ");
    scanf("%s", str2); // [cite: 81]

    while (1) {
        // Menu Driven Interface [cite: 74, 76]
        printf("\n--- String Operations Menu ---\n");
        printf("1. Length Calculation (strlen)\n");
        printf("2. String Copy (strcpy)\n");
        printf("3. String Concatenation (strcat)\n");
        printf("4. String Comparison (strcmp)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // [cite: 82]

        switch (choice) {
            case 1:
                // strlen() calculates length [cite: 73]
                printf("Length of first string: %lu\n", strlen(str1));
                printf("Length of second string: %lu\n", strlen(str2));
                break;

            case 2:
                // strcpy() copies one string to another [cite: 73]
                strcpy(temp, str1);
                printf("First string copied to temp: %s\n", temp);
                break;

            case 3:
                // strcat() joins two strings [cite: 73, 84]
                strcpy(temp, str1); // Use temp to keep original str1 intact
                strcat(temp, str2);
                printf("Concatenated string: %s\n", temp); 
                break;

            case 4:
                // strcmp() compares two strings [cite: 73]
                if (strcmp(str1, str2) == 0)
                    printf("Strings are equal.\n");
                else
                    printf("Strings are not equal.\n");
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}