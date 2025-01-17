#include <stdlib.h>
#include <stdio.h>

typedef void (*Callback)(int*);

void register_callback(int* data, Callback cb) {
    cb(data);
}

void increment_callback(int* value) {
    (*value)++;
    printf("Incremented: %d\n", *value);
}

void delayed_free_callback(int* value) {
    printf("Freeing: %d\n", *value);
    free(value);
}

int main() {
    int* data = (int*)malloc(sizeof(int));
    *data = 10;

    for (int i = 0; i < 5; i++) {
        register_callback(data, increment_callback);
    }

    register_callback(data, delayed_free_callback);

    // Potential use after free
    register_callback(data, increment_callback);

    return 0;
}
