#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = ptr;
    } else {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Node with value %d is inserted.\n", value);
}

int dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return -1;
    } else {
        struct node* temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
}

void display() {
    struct node* current = front;

    if (current == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    // Enqueue the values 23 and 32
    enqueue(23);
    enqueue(32);
    display();
    int z=dequeue();

    // Display the elements


    // Dequeue and print the values
    printf("Dequeued value: %d\n", z);

    // Display the elements again
    display();

    // Free allocated memory (optional)
    struct node* temp;
    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }

    return 0;
}
