#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* prev;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

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
        newNode->prev = current;
    }
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

void deleteAtEnd(struct node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev == NULL) {
        free(current);
        *head = NULL;
    } else {
        current->prev->next = NULL;
        free(current);
    }
}

void deleteAtBeginning(struct node** head) {
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

struct node* concatenate(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
        return list2;
    } else if (list2 == NULL) {
        return list1;
    }

    struct node* current = list1;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = list2;
    list2->prev = current;

    return list1;
}

struct node* unionDLL(struct node* list1, struct node* list2) {
    struct node* result = NULL;
    int seen[1000] = {0}; 

    struct node* current = list1;
    while (current != NULL) {
        if (!seen[current->data]) {
            append(&result, current->data);
            seen[current->data] = 1;
        }
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        if (!seen[current->data]) {
            append(&result, current->data);
            seen[current->data] = 1;
        }
        current = current->next;
    }

    return result;
}

struct node* intersection(struct node* list1, struct node* list2) {
    struct node* result = NULL;
    int seen[1000] = {0}; 

    struct node* current = list1;
    while (current != NULL) {
        seen[current->data]++;
        current = current->next;
    }

    current = list2;
    while (current != NULL) {
        if (seen[current->data] > 0) {
            append(&result, current->data);
            seen[current->data] = 0;
        }
        current = current->next;
    }

    return result;
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    append(&head1, 50);
    append(&head1, 70);

    append(&head2, 30);
    append(&head2, 70);

    head1 = concatenate(head1, head2);

    struct node* unionResult = unionDLL(head1, head2);

    struct node* intersectionResult = intersection(head1, head2);

    while (head1 != NULL) {
        struct node* temp = head1;
        head1 = head1->next;
        free(temp);
    }

    while (unionResult != NULL) {
        struct node* temp = unionResult;
        unionResult = unionResult->next;
        free(temp);
    }

    while (intersectionResult != NULL) {
        struct node* temp = intersectionResult;
        intersectionResult = intersectionResult->next;
        free(temp);
    }

    return 0;
}
