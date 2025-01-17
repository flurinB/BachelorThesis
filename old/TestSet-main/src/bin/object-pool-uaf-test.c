#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define POOL_SIZE 10

typedef struct {
    int id;
    bool is_active;
} Object;

Object object_pool[POOL_SIZE];

void init_pool() {
    for (int i = 0; i < POOL_SIZE; i++) {
        object_pool[i].id = i;
        object_pool[i].is_active = false;
    }
}

Object* acquire_object() {
    for (int i = 0; i < POOL_SIZE; i++) {
        if (!object_pool[i].is_active) {
            object_pool[i].is_active = true;
            return &object_pool[i];
        }
    }
    return NULL;
}

void release_object(Object* obj) {
    if (obj) obj->is_active = false;
}

int main() {
    init_pool();

    Object* obj1 = acquire_object();
    Object* obj2 = acquire_object();

    printf("Obj1 ID: %d\n", obj1->id);
    printf("Obj2 ID: %d\n", obj2->id);

    release_object(obj1);

    // Use after release (not technically a "free", but similar concept)
    printf("After release, Obj1 ID: %d\n", obj1->id);

    // Reacquire the same object
    Object* obj3 = acquire_object();
    printf("Obj3 ID: %d\n", obj3->id);

    // Potential use of released object
    printf("Obj1 ID again: %d\n", obj1->id);

    return 0;
}
