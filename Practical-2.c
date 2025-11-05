#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100  

int stack[MAX];
int top = -1;


int isFull() {
    return top == MAX - 1;
}


int isEmpty() {
    return top == -1;
}


void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("%d pushed onto stack.\n", value);
    }
}


int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    } else {
        int value = stack[top--];
        printf("%d popped from stack.\n", value);
        return value;
    }
}


void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Current Stack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}


void checkPalindrome() {
    char str[100];
    char rev[100];
    int i, j;

    printf("Enter a string to check palindrome: ");
    scanf("%s", str);

    int len = strlen(str);
    top = -1; 

    
    for (i = 0; i < len; i++) {
        push(str[i]);
    }


    for (i = 0; i < len; i++) {
        rev[i] = pop();
    }
    rev[len] = '\0';

  
    if (strcmp(str, rev) == 0)
        printf("The string '%s' is a Palindrome.\n", str);
    else
        printf("The string '%s' is NOT a Palindrome.\n", str);
}


int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Operations Menu ---\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check Palindrome using Stack\n");
        printf("4. Demonstrate Overflow and Underflow\n");
        printf("5. Display Stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                printf("\n-- Overflow Demo --\n");
                top = MAX - 1;
                push(10); 
                printf("\n-- Underflow Demo --\n");
                top = -1;
                pop(); 
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
