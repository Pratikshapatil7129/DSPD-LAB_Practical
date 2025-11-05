#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    if (arr == NULL || n == 0) {
        printf("NULL\n");
        return -1; 
    }

    int start = 0, end = n - 1, mid;

    while (start <= end) {
        mid = (start + end) / 2;

        
        printf("Examining value: %d at index %d\n", arr[mid], mid);

        
        if (arr[mid] == key) {
            printf("Found at index %d\n", mid);
            return mid;
        }
       
        else if (key > arr[mid]) {
            printf("Value greater than midpoint, adjusting start to index %d\n", mid + 1);
            start = mid + 1;
        }
      
        else {
            printf("Value less than midpoint, adjusting end to index %d\n", mid - 1);
            end = mid - 1;
        }
    }

    printf("Element not found!\n");
    return -1;
}

int main() {
    int n, key, i;
    int arr[100];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("NULL\n");
        return 0;
    }

    printf("Enter %d sorted elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    binarySearch(arr, n, key);

    return 0;
}
