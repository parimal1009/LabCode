#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct node {
    int data;
    struct node* next;
};

// Function to create a new node for SLL
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the SLL
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
    }
}

// Function to insert a node at the beginning of the SLL
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node at the end of the SLL
void deleteAtEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node* current = *head;
    struct node* previous = NULL;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    free(current);
    previous->next = NULL;
}

// Function to delete a node at the beginning of the SLL
void deleteAtBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to print the SLL in forward direction
void printForward(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse the SLL
void reverse(struct node** head) {
    struct node* prev = NULL;
    struct node* current = *head;
    struct node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

// Function to concatenate two SLLs
void concatenate(struct node** first, struct node* second) {
    if (*first == NULL) {
        *first = second;
    } else {
        struct node* current = *first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = second;
    }
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    // Append nodes to the end of the first SLL
    append(&head1, 50);
    append(&head1, 70);

    // Print the first SLL in forward direction
    printf("First SLL in forward direction:\n");
    printForward(head1);

    // Append nodes to the end of the second SLL
    append(&head2, 30);
    append(&head2, 40);

    // Print the second SLL in forward direction
    printf("Second SLL in forward direction:\n");
    printForward(head2);

    // Reverse the first SLL
    reverse(&head1);

    // Print the first SLL in reverse direction
    printf("First SLL in reverse direction:\n");
    printForward(head1);

    // Concatenate the second SLL to the end of the first SLL
    concatenate(&head1, head2);

    // Print the concatenated SLL
    printf("Concatenated SLL:\n");
    printForward(head1);

    // Free the memory and clean up
    while (head1 != NULL) {
        struct node* temp = head1;
        head1 = head1->next;
        free(temp);
    }

    return 0;
}
