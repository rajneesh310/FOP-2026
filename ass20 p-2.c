// write a c function to swap two numbers without using pointers
#include <stdio.h>
void swap(int a, int b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
    printf("Inside swap function: a = %d, b = %d\n", a, b);
}
int main() {
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);
    printf("Before swapping: x = %d, y = %d\n", x, y);
    swap(x, y);
    printf("After swapping: x = %d, y = %d\n", x, y);
    return 0;
}



