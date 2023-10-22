#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int count = 0;

struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s) {
    s->top = -1;
}

int isFull(st *s) {
    return s->top == MAX - 1;
}

int isEmpty(st *s) {
    return s->top == -1;
}

void push(st *s, int newItem) {
    if (isFull(s)) {
        printf("STACK FULL");
    } else {
        s->top++;
        s->items[s->top] = newItem;
    }
    count++;
}

void pop(st *s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY");
    } else {
        printf("ITEM POPPED: %d", s->items[s->top]);
        s->top--;
    }
    count--;
    printf("\n");
}

void printstack(st *s) {
    printf("stack");
    for (int i = 0; i < count; i++) {
        printf("%d", s->items[i]);
    }
    printf("\n");
}

int main() {
    st *s = (st *)malloc(sizeof(st));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    createEmptyStack(s);

    if (isEmpty(s)) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }

    if (!isFull(s)) {
        push(s, 42);
        printf("Pushed 42 onto the stack\n");
    } else {
        printf("Stack is full, cannot push\n");
    }

    if (!isEmpty(s)) {
        int item = s->items[s->top--];
        printf("Popped %d from the stack\n", item);
    } else {
        printf("Stack is empty, cannot pop\n");
    }

    free(s);
    return 0;
}
//que insert and delete