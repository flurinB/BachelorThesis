#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int value;
    bool is_deleted;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->is_deleted = false;
    node->next = NULL;
    return node;
}

void lazy_delete(Node* node) {
    if (node) node->is_deleted = true;
}

void print_list(Node* head) {
    Node* current = head;
    while (current) {
        if (!current->is_deleted) {
            printf("%d ", current->value);
        }
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);

    print_list(head);

    lazy_delete(head->next);
    print_list(head);

    // Actual deletion (simulating garbage collection)
    Node* to_delete = head->next;
    head->next = head->next->next;
    free(to_delete);

    // Use after free
    printf("Deleted node value: %d\n", to_delete->value);

    return 0;
}
