#include <stdio.h>

int binary_search_recursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            return binary_search_recursive(arr, mid + 1, right, target);
        else
            return binary_search_recursive(arr, left, mid - 1, target);
    }

    return -1; // Element not found
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = binary_search_recursive(arr, 0, 9, target);

    if (result != -1) {
        printf("Element found at position %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}


