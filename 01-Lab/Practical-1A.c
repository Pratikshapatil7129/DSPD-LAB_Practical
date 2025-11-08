#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int sum_even = 0, sum_odd = 0;

 
    printf("Enter number of elements: ");
    scanf("%d", &n);

  
    printf("Enter %d numbers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        if((i + 1) % 2 == 0)      
            sum_even += arr[i];
        else                     
            sum_odd += arr[i];
    }


    printf("Sum of numbers at odd positions = %d\n", sum_odd);
    printf("Sum of numbers at even positions = %d\n", sum_even);

    return 0;
}
