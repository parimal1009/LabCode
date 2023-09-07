#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    int data;
    struct node* prev;
    struct node* next;
};

// Function to create a new node for DLL
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the DLL
void append(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// Function to concatenate two DLLs
void concatenate(struct node** head1, struct node* head2) {
    if (*head1 == NULL) {
        *head1 = head2; // If the first list is empty, simply point it to the second list
    } else if (head2 != NULL) {
        struct node* current = *head1;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = head2;
        head2->prev = current;
    }
}

// Function to print the DLL in forward direction
void printForward(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;

    // Append nodes to the first DLL
    append(&list1, 1);
    append(&list1, 2);
    append(&list1, 3);

    // Append nodes to the second DLL
    append(&list2, 4);
    append(&list2, 5);

    // Print both DLLs before concatenation
    printf("DLL 1 before concatenation:\n");
    printForward(list1);

    printf("DLL 2 before concatenation:\n");
    printForward(list2);

    // Concatenate the second DLL to the first DLL
    concatenate(&list1, list2);

    // Print the concatenated DLL
    printf("DLL after concatenation:\n");
    printForward(list1);

    // Free the memory and clean up
    while (list1 != NULL) {
        struct node* temp = list1;
        list1 = list1->next;
        free(temp);
    }

    return 0;
}
