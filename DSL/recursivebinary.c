#include <stdio.h>

int binarySearch(int arr[], int low, int high, int target) {
    if (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            return binarySearch(arr, mid + 1, high, target);
        } else {
            return binarySearch(arr, low, mid - 1, target);
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Enter the element to search for: ");
    int w, q = -1;
    scanf("%d", &w);

    q = binarySearch(arr, 0, 9, w);

    if (q == -1) {
        printf("Element not found");
    } else {
        printf("Found at %d position", q);
    }

    return 0;
}
