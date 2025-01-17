#include <stdlib.h>
#include <stdio.h>

void initialize(int** ptr, int value) {
    *ptr = (int*)malloc(sizeof(int));
    **ptr = value;
}

void modify_value(int* ptr, int modifier) {
    *ptr += modifier;
}

void print_value(int* ptr) {
    printf("Value: %d\n", *ptr);
}

void nested_operation(int* ptr) {
    for (int i = 0; i < 5; i++) {
        modify_value(ptr, i);
    }
}

void perform_complex_operations(int* ptr) {
    for (int i = 0; i < 50; i++) {
        nested_operation(ptr);
        print_value(ptr);
    }
}

int main() {
    int* ptr;
    
    initialize(&ptr, 10);
    perform_complex_operations(ptr);
    
    free(ptr);
    
    // Use after free
    nested_operation(ptr);
    print_value(ptr);
    
    return 0;
}
