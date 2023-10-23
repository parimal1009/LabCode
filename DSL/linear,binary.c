#include <stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Input: ");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n");

    int key;
    printf("Element to be searched: ");
    scanf("%d", &key);

    int linearResult = linearSearch(arr, size, key);
    if (linearResult != -1) {
        printf("Element is present at index %d\n", linearResult);
    } else {
        printf("Element not found.\n");
    }

    int binaryResult = binarySearch(arr, size, key);
    if (binaryResult != -1) {
        printf("Element is present at index %d\n", binaryResult);
    } else {
        printf("Element not found.\n");
    }

    return 0;
}
