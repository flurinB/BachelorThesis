#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int* data;
    int size;
} Array;

void initialize_array(Array* arr, int size) {
    arr->data = (int*)malloc(size * sizeof(int));
    arr->size = size;
    for (int i = 0; i < size; i++) {
        arr->data[i] = i;
    }
}

void process_array(Array* arr) {
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] *= 2;
    }
}

void nested_loop_operation(Array* arr) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 5; j++) {
            process_array(arr);
        }
    }
}

void complex_operation(Array* arr) {
    for (int i = 0; i < 100; i++) {
        nested_loop_operation(arr);
        printf("Iteration %d, First element: %d\n", i, arr->data[0]);
    }
}

void cleanup(Array* arr) {
    free(arr->data);
    arr->data = NULL;
    arr->size = 0;
}

int main() {
    Array arr;
    initialize_array(&arr, 10);
    
    complex_operation(&arr);
    
    cleanup(&arr);
    
    // Use after free
    printf("After cleanup, first element: %d\n", arr.data[0]);
    
    return 0;
}
