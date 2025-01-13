#include <stdlib.h>
#include <stdio.h>

void initialize(int* ptr, int value) {
    *ptr = value;
}

void print_value(int* ptr) {
    printf("Value: %d\n", *ptr);
}

void perform_operations(int* ptr) {
    for (int i = 0; i < 10; i++) {
        *ptr += i;
        print_value(ptr);
    }
}

int main() {
    int* ptr = (int*)malloc(sizeof(int));
    
    initialize(ptr, 5);
    perform_operations(ptr);
    
    free(ptr);
    
    // Use after free
    print_value(ptr);
    
    return 0;
}
