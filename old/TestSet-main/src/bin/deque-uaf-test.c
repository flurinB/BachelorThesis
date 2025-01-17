#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
} Deque;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->prev = node->next = NULL;
    return node;
}

void push_front(Deque* deque, int value) {
    Node* node = create_node(value);
    if (!deque->front) {
        deque->front = deque->rear = node;
    } else {
        node->next = deque->front;
        deque->front->prev = node;
        deque->front = node;
    }
}

int pop_rear(Deque* deque) {
    if (!deque->rear) return -1;
    Node* temp = deque->rear;
    int value = temp->value;
    deque->rear = temp->prev;
    if (deque->rear) deque->rear->next = NULL;
    else deque->front = NULL;
    free(temp);
    return value;
}

int main() {
    Deque deque = {NULL, NULL};

    for (int i = 0; i < 5; i++) {
        push_front(&deque, i);
    }

    for (int i = 0; i < 6; i++) {
        printf("Popped: %d\n", pop_rear(&deque));
    }

    // Use after free (accessing freed nodes)
    printf("Front: %d\n", deque.front->value);

    return 0;
}
