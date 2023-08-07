#include <stdio.h>

int main() {
    int arr[100], n, i, k, temp, min_index;

    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        for (k = i + 1; k < n; k++) {
            if (arr[k] < arr[min_index]) {
                min_index = k;
            }
        }

        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    printf("Sorted array: ");
    for (k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}

