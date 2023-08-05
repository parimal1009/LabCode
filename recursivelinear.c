#include<stdio.h>

int searchRecursive(int arr[], int n, int w, int i) {
    if (i >= n) {
        return -1;
    }
    
    if (arr[i] == w) {
        return i;
    }
    
    return searchRecursive(arr, n, w, i+1);
}

int main() {
    int n, i, arr[10], w;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &w);

    int q = searchRecursive(arr, n, w, 0);

    if (q == -1) {
        printf("Element not found\n");
    } else {
        printf("Element found at position %d\n", q );
    }

    return 0;
}

