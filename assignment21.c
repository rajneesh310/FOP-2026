#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char ch;

    // Opening the source file in read mode [cite: 41, 42]
    sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file.\n");
        exit(1);
    }

    // Opening the destination file in write mode 
    destFile = fopen("destination.txt", "w");
    if (destFile == NULL) {
        printf("Error: Cannot open destination file.\n");
        fclose(sourceFile);
        exit(1);
    }

    // Reading characters one by one and writing to the destination [cite: 43]
    // This process continues until the end of the file (EOF) is reached [cite: 44]
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n"); // [cite: 54]

    // Closing the files to free memory and save changes 
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}