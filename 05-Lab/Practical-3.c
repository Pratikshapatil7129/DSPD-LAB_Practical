#include <stdio.h>
#define MAX 100  

char queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return rear == MAX - 1;
}


int isEmpty() {
    return (front == -1 || front > rear);
}

void  insert(char item) {
    if (isFull()) {
        printf("Queue Overflow! Cannot insert '%c'\n", item);
        return;
    }
    if (front == -1) {
        front = 0;
    }
    queue[++rear] = item;
    printf("'%c' inserted into Queue.\n", item);
}


void delete() {
    if (isEmpty()) {
        printf("Queue Underflow! No element to delete.\n");
        return;
    }
    printf("Deleted element: '%c'\n", queue[front]);
    front++;
    if (front > rear) { 
        front = rear = -1;
    }
}


void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Current Queue elements are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
}


void demonstrateOverflowUnderflow() {
    printf("\n   Demonstrating Overflow   \n");
    rear = MAX - 1;  
    insert('Z');    

    printf("\n   Demonstrating Underflow   \n");
    front = -1;
    rear = -1;       
    delete();       
}


int main() {
    int choice;
    char item;

    while (1) {
        printf("\n    Queue Operations Menu    \n");
        printf("1. Insert an Element into Queue\n");
        printf("2. Delete an Element from Queue\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Queue Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character to insert: ");
                scanf(" %c", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                demonstrateOverflowUnderflow();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

