
#include <stdio.h>
int binarySearch(int arr[], int n, int key) {

    if (arr == NULL || n == 0) {
        printf("NULL\n");
        return -1;
    }

    int start = 0, end = n - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        printf("Mid value: %d at index %d\n", arr[mid], mid);
        if (arr[mid] == key) {
            printf("Value found at index %d\n", mid);
            return 1;  
        }
       
        else if (key > arr[mid]) {
           
            start = mid + 1;
        }
        
        else {
            
            end = mid - 1;
        }
    }

    
    printf("Value not found.\n");
    return 0; 
}

int main() {
    int n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to search: ");
    scanf("%d", &key);

    binarySearch(arr, n, key);

    return 0;
}
