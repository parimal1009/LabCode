#include <stdio.h>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target;

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int b = 0, e = 9;
    int q = -1;

    while (b <= e) {
        int mid = b + (e - b) / 2;

        if (arr[mid] == target) {
            q = mid;
            break;
        } else {
            if (target > arr[mid]) {
                b = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    }

    if (q == -1) {
        printf("Element not found\n");
    } else {
        printf("Found at position %d\n", q);
    }

    return 0;
}


