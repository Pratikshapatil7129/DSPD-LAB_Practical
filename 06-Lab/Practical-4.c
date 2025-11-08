#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head) {
    struct Node* temp = head;
    int count = 0;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
        count++;
    }
    printf("NULL\n");
    printf("Total number of nodes = %d\n", count);
}

int main() {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int num;

    printf("Enter elements (enter 0 to stop):\n");

    while (1) {
        scanf("%d", &num);

        if (num == 0)
            break; 
        newNode = createNode(num);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    display(head);

    return 0;
}
