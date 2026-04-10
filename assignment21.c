#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *sourceFile, *destFile;
    char ch;

    
    sourceFile = fopen("source.txt", "r");
    if (sourceFile == NULL) {
        printf("Error: Cannot open source file.\n");
        exit(1);
    }

    
    destFile = fopen("destination.txt", "w");
    if (destFile == NULL) {
        printf("Error: Cannot open destination file.\n");
        fclose(sourceFile);
        exit(1);
    }

    
    while ((ch = fgetc(sourceFile)) != EOF) {
        fputc(ch, destFile);
    }

    printf("File copied successfully.\n"); // [cite: 54]

    
    fclose(sourceFile);
    fclose(destFile);

    return 0;
}