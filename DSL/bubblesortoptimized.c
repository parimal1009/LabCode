#include <stdio.h>

int main() {
    int arr[100], n, i, k, temp;
    int flag;

    printf("Enter the number of array elements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter array element: ");
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++) {
        flag = 0;

        for (k = 0; k < n - i - 1; k++) {
            if (arr[k] > arr[k + 1]) {
                temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
                flag = 1;
            }
        }

        if (flag == 0) {
            break;
        }
    }

    printf("Sorted array: ");
    for (k = 0; k < n; k++) {
        printf("%d ", arr[k]);
    }

    return 0;
}

