#include<stdio.h>

int main() {
    int a[50], temp;
    int i, j, n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sorting positive numbers to the beginning of the array
    j = 0; // j will be used to track the position for positive numbers
    for(i = 0; i < n; i++) {
        if(a[i] > 0) {
            // Swap positive number with the element at position j
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j++; // Move j to the next position
        }
    }

    // Printing the sorted array where positive numbers come first
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
