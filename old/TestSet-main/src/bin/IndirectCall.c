#include <stdio.h>

// Function pointer type definition
typedef void (*Operation)(int);

// Functions for direct calls
void printSquare(int x) {
    printf("Square of %d is %d\n", x, x * x);
}

void printDouble(int x) {
    printf("Double of %d is %d\n", x, x * 2);
}

// Function that will be called indirectly
void printTriple(int x) {
    printf("Triple of %d is %d\n", x, x * 3);
}

// Function that takes a function pointer as parameter
void processNumber(int num, Operation op) {
    printf("Processing %d...\n", num);
    op(num);  // Indirect function call through pointer
}

int main() {
    int number = 5;
    // Direct function calls
    printf("\nDirect function calls:\n");
    printSquare(number);
    printDouble(number);
    // Indirect function calls using function pointer
    printf("\nIndirect function calls:\n");
    Operation op1 = printTriple;
    op1(number);  // Indirect call through function pointer
    // Indirect call through function parameter
    processNumber(number, printSquare);
    processNumber(number, printTriple);
    return 0;
}
