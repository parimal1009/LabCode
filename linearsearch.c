#include <stdio.h>

int main() {
    int n, i, arr[10], w, q = -1;

    printf("enter no. of arrays: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("array elements: ");
        scanf("%d", &arr[i]);
    }

    printf("enter element to search for: ");
    scanf("%d", &w);

    for (i = 0; i < n; i++) {
        if (w == arr[i]) {
            q = i;
            break;
        }
    }

    if (q == -1) {
        printf("element not found");
    } else {
        printf("found at %d position", q);
    }

    return 0;
}
