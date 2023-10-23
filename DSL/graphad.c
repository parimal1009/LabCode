#include <stdio.h>
#define V 4

void init(int arr[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int arr[V][V]) {
    int i, j, w;
    printf("Enter vertices of the edge: ");
    scanf("%d %d", &i, &j);
    printf("Enter weight: ");
    scanf("%d", &w);
    arr[i][j] = w;
    arr[j][i] = w;
}

void printMatrix(int arr[V][V]) {
    for (int i = 0; i < V; i++) {
        printf("\n");
        for (int j = 0; j < V; j++) {
            printf("%d ", arr[i][j]);
        }
    }
}

int main() {
    int adj[V][V];
    init(adj);

    int choice = -1;
    while (choice != 0) {
        printf("\nEnter 1 to add an edge\nEnter 2 to print the matrix\nEnter 0 to exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEdge(adj);
                break;
            case 2:
                printf("Adjacency Matrix:");
                printMatrix(adj);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
