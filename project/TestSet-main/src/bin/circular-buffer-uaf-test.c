#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 5

typedef struct {
    int* data;
    int head;
    int tail;
    int size;
} CircularBuffer;

void init_buffer(CircularBuffer* buf) {
    buf->data = (int*)malloc(BUFFER_SIZE * sizeof(int));
    buf->head = buf->tail = buf->size = 0;
}

void enqueue(CircularBuffer* buf, int value) {
    if (buf->size < BUFFER_SIZE) {
        buf->data[buf->tail] = value;
        buf->tail = (buf->tail + 1) % BUFFER_SIZE;
        buf->size++;
    }
}

int dequeue(CircularBuffer* buf) {
    if (buf->size > 0) {
        int value = buf->data[buf->head];
        buf->head = (buf->head + 1) % BUFFER_SIZE;
        buf->size--;
        return value;
    }
    return -1;
}

int main() {
    CircularBuffer buf;
    init_buffer(&buf);

    for (int i = 0; i < 10; i++) {
        enqueue(&buf, i);
    }

    for (int i = 0; i < 7; i++) {
        printf("Dequeued: %d\n", dequeue(&buf));
    }

    free(buf.data);

    // Use after free
    printf("After free: %d\n", dequeue(&buf));

    return 0;
}
