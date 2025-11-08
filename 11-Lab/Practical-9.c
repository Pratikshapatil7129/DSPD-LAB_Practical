
#include <stdio.h>
#define SIZE 7

int hash(int key) {
    return key % SIZE;
}

void insert(int hashTable[], int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) return;
    }
    hashTable[(index + i) % SIZE] = key;
}

void display(int hashTable[]) {
    printf("\nFinal Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d -> %d\n", i, hashTable[i]);
        else
            printf("Slot %d -> NULL\n", i);
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;

    int n, key;
    printf("Enter number of keys to insert (max %d): ", SIZE);
    scanf("%d", &n);

    if (n > SIZE) return 0;

    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);
        insert(hashTable, key);
    }

    display(hashTable);
    return 0;
}
