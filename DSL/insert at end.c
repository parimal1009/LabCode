#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void fix(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newnode;
    }
}

int main() {
    struct node* head = NULL;

    fix(&head, 12);
    fix(&head, 22);
    fix(&head, 30);
    fix(&head, 44);
    fix(&head, 50);

    struct node* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
