#include <stdio.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

struct Stack {
    int data[MAX_VERTICES];
    int top;
};

void initGraph(int vertices) {
    numVertices = vertices;
    for (int v = 0; v < vertices; v++) {
        visited[v] = 0;
        for (int u = 0; u < vertices; u++) {
            graph[v][u] = 0;
        }
    }
}

void addEdge(int start, int end) {
    graph[start][end] = 1;
    graph[end][start] = 1;
}

void push(struct Stack *s, int item) {
    if (s->top == MAX_VERTICES - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->data[++(s->top)] = item;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

void DFSWithStack(int startVertex) {
    struct Stack stack;
    stack.top = -1;
    int currentVertex;
    push(&stack, startVertex);
    visited[startVertex] = 1;

    printf("DFS starting from vertex %d: ", startVertex);

    while (!isEmpty(&stack)) {
        currentVertex = pop(&stack);
        printf("%d ", currentVertex);

        int u;
        for (u = 0; u < numVertices; u++) {
            if (graph[currentVertex][u] == 1 && !visited[u]) {
                push(&stack, u);
                visited[u] = 1;
            }
        }
    }
}

int main() {
    int vertices, edges;
    int e;
    int start, end;
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (e = 0; e < edges; e++) {
        printf("Enter edge %d (start end): ", e + 1);
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    DFSWithStack(startVertex);

    return 0;
}
