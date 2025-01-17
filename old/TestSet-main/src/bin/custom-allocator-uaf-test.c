#include <stdlib.h>
#include <stdio.h>

#define POOL_SIZE 1024

char memory_pool[POOL_SIZE];
int next_free = 0;

void* custom_malloc(size_t size) {
    if (next_free + size > POOL_SIZE) return NULL;
    void* ptr = &memory_pool[next_free];
    next_free += size;
    return ptr;
}

void custom_free(void* ptr) {
    // This implementation doesn't actually free memory
}

int main() {
    int* arr1 = (int*)custom_malloc(5 * sizeof(int));
    int* arr2 = (int*)custom_malloc(3 * sizeof(int));

    for (int i = 0; i < 5; i++) {
        arr1[i] = i;
    }

    custom_free(arr1);

    // Use after free
    printf("After free: %d\n", arr1[2]);

    for (int i = 0; i < 3; i++) {
        arr2[i] = i * 10;
    }

    // Potential use of freed memory
    printf("Potentially overwritten: %d\n", arr1[2]);

    return 0;
}
