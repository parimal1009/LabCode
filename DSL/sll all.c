#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
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
    }
}

void insertAtRandomLocation(struct node** head, int data, int position) {
    struct node* newNode = createNode(data);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node* current = *head;
    int i = 0;
    while (i < position - 1 && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Invalid position for insertion.\n");
        free(newNode);
    } else {
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteFromBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromLast(struct node** head) {
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

void deleteNodeAfterLocation(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* current = *head;
    int i = 0;
    while (i < position && current != NULL) {
        current = current->next;
        i++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Invalid position for deletion.\n");
    } else {
        struct node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
}

void printForward(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

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

    int choice;
    int data;
    int position;

    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at Last\n3. Insert at Random Location\n4. Delete from Beginning\n5. Delete from Last\n6. Delete Node After Specified Location\n7. Reverse\n8. Concatenate\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head1, data);
                break;
            case 2:
                printf("Enter data to insert at the last: ");
                scanf("%d", &data);
                insertAtLast(&head1, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter the position for insertion: ");
                scanf("%d", &position);
                insertAtRandomLocation(&head1, data, position);
                break;
            case 4:
                deleteFromBeginning(&head1);
                break;
            case 5:
                deleteFromLast(&head1);
                break;
            case 6:
                printf("Enter the position to delete after: ");
                scanf("%d", &position);
                deleteNodeAfterLocation(&head1, position);
                break;
            case 7:
                reverse(&head1);
                printf("List reversed.\n");
                break;
            case 8:
                concatenate(&head1, head2);
                printf("Concatenated.\n");
                break;
            case 9:
                printf("Linked List: ");
                printForward(head1);
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
