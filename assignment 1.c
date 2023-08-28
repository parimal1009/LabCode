#include <stdio.h>

int main() {
    int n, i, arr[10], w;
    int occurrences[10]; 
    int count = 0; 

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter array element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search for: ");
    scanf("%d", &w);

    for (i = 0; i < n; i++) {
        if (w == arr[i]) {
            occurrences[count] = i;
            count++;
        }
    }

    if (count == 0) {
        printf("Element not found.\n");
    } else {
        printf("Element found at positions: ");
        for (i = 0; i < count; i++) {
            printf("%d", occurrences[i]);
            if (i < count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }

    return 0;
}

