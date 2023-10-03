#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void concatenate(struct node** firstList, struct node* secondList) {
    if (*firstList == NULL) {
        *firstList = secondList;
    } else {
        struct node* current = *firstList;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = secondList;
    }
}

int main() {
    struct node* firstList = (struct node*)malloc(sizeof(struct node));
    struct node* secondList = (struct node*)malloc(sizeof(struct node));

    firstList->data = 45;
    firstList->next = NULL;

    secondList->data = 60;
    secondList->next = NULL;

    struct node* current = firstList;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    current = secondList;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    concatenate(&firstList, secondList);

    current = firstList;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }

    free(firstList);

    return 0;
}
