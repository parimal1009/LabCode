#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void insertAtLast(struct node** head, int data) {
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

void insertAtRandomLocation(struct node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct node* newNode = createNode(data);
    struct node* current = *head;

    for (int i = 0; i < position - 1; i++) {
        if (current == NULL) {
            printf("Invalid position for insertion.\n");
            free(newNode);
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next = newNode;
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

void deleteFromBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

void deleteFromLast(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev == NULL) {
        *head = NULL;
    } else {
        current->prev->next = NULL;
    }

    free(current);
}

void deleteNodeAfterLocation(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* current = *head;

    for (int i = 0; i < position; i++) {
        if (current == NULL) {
            printf("Invalid position for deletion.\n");
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid position for deletion.\n");
        return;
    }

    struct node* temp = current->next;
    if (temp != NULL) {
        current->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = current;
        }
    }
    free(temp);
}

void printForward(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void concatenate(struct node** first, struct node* second) {
    if (*first == NULL) {
        *first = second;
    } else if (second != NULL) {
        struct node* firstEnd = *first;
        while (firstEnd->next != NULL) {
            firstEnd = firstEnd->next;
        }
        firstEnd->next = second;
        second->prev = firstEnd;
    }
}

void reverse(struct node** head) {
    struct node* current = *head;
    struct node* temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    struct node* head = NULL;

    int choice;
    int data;
    int position;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at Last\n3. Insert at Random Location\n4. Delete from Beginning\n5. Delete from Last\n6. Delete Node After Specified Location\n7. Display\n8. Concatenate\n9. Reverse\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the last: ");
                scanf("%d", &data);
                insertAtLast(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position for insertion: ");
                scanf("%d", &position);
                insertAtRandomLocation(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromLast(&head);
                break;
            case 6:
                printf("Enter the position to delete after: ");
                scanf("%d", &position);
                deleteNodeAfterLocation(&head, position);
                break;
            case 7:
                printf("Doubly Linked List: ");
                printForward(head);
                break;
            case 8:
                printf("Concatenation is not supported in a doubly linked list.\n");
                break;
            case 9:
                reverse(&head);
                printf("List reversed.\n");
                break;
            case 10:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
