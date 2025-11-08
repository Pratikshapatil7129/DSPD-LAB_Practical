
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int value) {
    struct Node* newNode = createNode(value);
    if (root == NULL)
        return newNode;

    struct Node* queue[50];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } else
            queue[rear++] = temp->left;

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } else
            queue[rear++] = temp->right;
    }
    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("NULL\n");
        return;
    }

    struct Node* queue[50];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->data == key) {
            printf("Found\n");
            return;
        }

        if (temp->left != NULL)
            queue[rear++] = temp->left;
        if (temp->right != NULL)
            queue[rear++] = temp->right;
    }

    printf("NULL\n");
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes to insert: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPreorder Traversal: ");
    preorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n\nEnter value to search: ");
    scanf("%d", &key);
    search(root, key);

    return 0;
}