#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void append(struct node** head, int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
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
