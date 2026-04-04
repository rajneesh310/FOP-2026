#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], temp[100];
    int length, i, j, isPalindrome = 1;

    // INPUT: Accept strings from the user
    printf("Enter a string: ");
    gets(str1); // Using gets to accept strings with spaces
    
    printf("Enter another string for equality and substring check: ");
    gets(str2);

    // i) Calculate length of string
    length = strlen(str1);
    printf("\nLength of string = %d", length);

    // ii) String reversal
    strcpy(temp, str1); // Copy to temp to preserve original for other checks
    printf("\nReversed string = ");
    for (i = length - 1; i >= 0; i--) {
        printf("%c", temp[i]);
    }

    // iii) Equality check
    if (strcmp(str1, str2) == 0) {
        printf("\nStrings are equal");
    } else {
        printf("\nStrings are not equal");
    }

    // iv) Check palindrome
    for (i = 0; i < length / 2; i++) {
        if (str1[i] != str1[length - 1 - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("\nThe string is a Palindrome");
    } else {
        printf("\nThe string is not a Palindrome");
    }

    // v) Check substring
    if (strstr(str1, str2) != NULL) {
        printf("\nSubstring found in main string\n");
    } else {
        printf("\nSubstring not found in main string\n");
    }

    return 0;
}