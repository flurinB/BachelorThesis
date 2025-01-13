#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    int* data;
    void (*callback)(int*);
} AsyncOperation;

void process_async(AsyncOperation* op) {
    sleep(1);  // Simulate async operation
    op->callback(op->data);
}

void callback(int* data) {
    printf("Callback with data: %d\n", *data);
}

int main() {
    AsyncOperation op;
    op.data = (int*)malloc(sizeof(int));
    *op.data = 42;
    op.callback = callback;

    process_async(&op);

    free(op.data);

    // Simulate another async operation with the same structure
    sleep(1);
    
    // Use after free in callback
    process_async(&op);

    return 0;
}
