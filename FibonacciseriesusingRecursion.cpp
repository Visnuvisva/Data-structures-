#include <stdio.h>

// Function to find the nth Fibonacci number using recursion
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Enter the value of n to find the nth Fibonacci number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Invalid input. n should be a non-negative integer.\n");
    } else {
        printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n));
    }

    return 0;
}

