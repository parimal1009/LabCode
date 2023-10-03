#include <stdio.h>

void quicksort(int arr[100], int first, int last) {
    int i, j, pivot, temp;
    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (i < last && arr[i] <= arr[pivot])
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;

        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1); // Added the element number placeholder
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("Sorted array:");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}    
