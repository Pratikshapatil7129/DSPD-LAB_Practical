#include <stdio.h>

int main() {
    int i, n, search, first = 0, last, mid, found = 0;

    printf("Enter the range of the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d sorted elements of array:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    last = n - 1;

    printf("Enter element to search: ");
    scanf("%d", &search);

    while (first <= last) {
        mid = (first + last) / 2;

        printf("first of array is %d\n", first + 1);
        printf("last of array is %d\n", last + 1);
        printf("Mid of array is %d\n", mid + 1);
        printf("The array is:\n");
        for (i = first; i <= last; i++) {
            printf("%d ", a[i]);
        }
        printf("\n\n");

        if (a[mid] == search) {
            printf("The element %d is located at position %d.\n", search, mid + 1);
            found = 1;
            break;
        } else if (search < a[mid]) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }

    if (!found) {
        printf("The element %d is not present in the array.\n", search);
    }

    return 0;
}


    
