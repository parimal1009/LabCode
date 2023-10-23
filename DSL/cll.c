#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = newNode; // Circular reference to itself
    return newNode;
}

void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself in a circular list
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
    }
}

void insertAtLast(struct node** head, int data) {
    struct node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode; // Point to itself in a circular list
    } else {
        newNode->next = (*head)->next;
        (*head)->next = newNode;
        *head = newNode;
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
        current = current->next;
        if (current == *head) {
            printf("Invalid position for insertion.\n");
            free(newNode);
            return;
        }
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteFromBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* temp = (*head)->next;
    if (temp == *head) {
        *head = NULL;
    } else {
        (*head)->next = temp->next;
    }
    free(temp);
}

void deleteFromLast(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* current = *head;
    if (current->next == current) {
        *head = NULL;
    } else {
        while (current->next->next != *head) {
            current = current->next;
        }
        struct node* temp = current->next;
        current->next = temp->next;
        *head = current;
        free(temp);
    }
}

void deleteNodeAfterLocation(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* current = *head;
    for (int i = 0; i < position; i++) {
        current = current->next;
        if (current == *head) {
            printf("Invalid position for deletion.\n");
            return;
        }
    }

    struct node* temp = current->next;
    if (temp == *head) {
        *head = current;
    }
    current->next = temp->next;
    free(temp);
}

void printForward(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);
    printf("\n");
}

void concatenate(struct node** first, struct node* second) {
    if (*first == NULL) {
        *first = second;
    } else if (second != NULL) {
        struct node* firstEnd = (*first)->next;
        struct node* secondEnd = second->next;
        (*first)->next = second;
        firstEnd->next = secondEnd;
    }
}

int main() {
    struct node* head = NULL;

    int choice;
    int data;
    int position;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at Last\n3. Insert at Random Location\n4. Delete from Beginning\n5. Delete from Last\n6. Delete Node After Specified Location\n7. Display\n8. Concatenate\n9. Exit\n");
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
                printf("Linked List: ");
                printForward(head);
                break;
            case 8:
                printf("Concatenation is not supported in a circular list.\n");
                break;
            case 9:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
