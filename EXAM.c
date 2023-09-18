#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertattheEnd(struct Node** head, char data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

char findSmallest(struct Node* head) {
    if (head == NULL) {
        // Handle the case where the list is empty
        return '\0'; // Return a null character to indicate an empty list
    }

    char smallest = head->data;
    while (head != NULL) {
        if (head->data < smallest) {
            smallest = head->data;
        }
        head = head->next;
    }
    return smallest;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertattheEnd(&head, 'A');
    insertattheEnd(&head, 'Z');
    insertattheEnd(&head, 'L');
    insertattheEnd(&head, 'X');
    insertattheEnd(&head, 'B');

    printf("Original list: ");
    printList(head);

    char smallest = findSmallest(head);

    if (smallest != '\0') {
        printf("Smallest element in the list: %c\n", smallest);
    } else {
        printf("The list is empty.\n");
    }

    return 0;
}

