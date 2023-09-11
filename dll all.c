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
    newNode->next = *head;
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;
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
    while (current->next != NULL) {
        current = current->next;
    }

    if (current->prev != NULL) {
        current->prev->next = NULL;
    }

    free(current);
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

void printForward(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void reverse(struct node** head) {
    struct node* temp = NULL;
    struct node* current = *head;

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

void concatenate(struct node** first, struct node* second) {
    if (*first == NULL) {
        *first = second;
    } else {
        struct node* current = *first;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = second;
        if (second != NULL) {
            second->prev = current;
        }
    }
}

int search(struct node* head, int data) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

struct node* findUnion(struct node* first, struct node* second) {
    struct node* result = NULL;
    struct node* current = first;

    while (current != NULL) {
        append(&result, current->data);
        current = current->next;
    }

    current = second;
    while (current != NULL) {
        if (!search(result, current->data)) {
            append(&result, current->data);
        }
        current = current->next;
    }

    return result;
}

struct node* findIntersection(struct node* first, struct node* second) {
    struct node* result = NULL;
    struct node* current = first;

    while (current != NULL) {
        if (search(second, current->data)) {
            append(&result, current->data);
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

    printf("First DLL in forward direction:\n");
    printForward(head1);

    append(&head2, 30);
    append(&head2, 40);

    printf("Second DLL in forward direction:\n");
    printForward(head2);

    reverse(&head1);

    printf("First DLL in reverse direction:\n");
    printForward(head1);

    concatenate(&head1, head2);

    printf("Concatenated DLL:\n");
    printForward(head1);

    struct node* unionResult = findUnion(head1, head2);
    printf("Union of DLLs:\n");
    printForward(unionResult);

    struct node* intersectionResult = findIntersection(head1, head2);
    printf("Intersection of DLLs:\n");
    printForward(intersectionResult);

    while (head1 != NULL) {
        struct node* temp = head1;
        head1 = head1->next;
        free(temp);
    }

    while (head2 != NULL) {
        struct node* temp = head2;
        head2 = head2->next;
        free(temp);
    }

    return 0;
}
