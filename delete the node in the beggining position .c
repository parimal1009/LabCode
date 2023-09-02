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

int main() {
    struct node* head = NULL;

    append(&head, 50);
    append(&head, 70);

    struct node* current = head;
    while (current != NULL) {
        printf("%d\n", current->data);
        struct node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
