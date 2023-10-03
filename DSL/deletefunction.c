#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void deleteAtBeginning(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

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
    while (current->next->next != NULL) {
        current = current->next;
    }

    struct node* temp = current->next;
    current->next = NULL;
    free(temp);
}

void deleteAtPosition(struct node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct node* current = *head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL) {
        printf("Position exceeds the length of the list.\n");
        return;
    }

    struct node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}
