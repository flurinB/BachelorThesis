#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = node->right = NULL;
    return node;
}

void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = create_node(value);
    } else if (value < (*root)->value) {
        insert(&((*root)->left), value);
    } else {
        insert(&((*root)->right), value);
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->value);
        inorder(root->right);
    }
}

void free_tree(Node* root) {
    if (root) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int values[] = {5, 3, 7, 1, 9, 4, 6};

    for (int i = 0; i < 7; i++) {
        insert(&root, values[i]);
    }

    inorder(root);
    printf("\n");

    free_tree(root);

    // Use after free
    inorder(root);

    return 0;
}
