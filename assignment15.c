#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   
int main() {
    int count, i;

   
    printf("Enter how many random numbers you want: ");
    scanf("%d", &count);

  
    srand(time(0));

    printf("Pseudo Random Numbers:\n");

    
    for (i = 0; i < count; i++) {
       
        printf("%d ", rand());
    }

    printf("\n");

    return 0;
}