#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node for DLL
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of the DLL
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

// Function to insert a node at the beginning of the DLL
void insertAtBeginning(struct node** head, int data) {
    struct node* newNode = createNode(data);
    newNode->next = *head;
    newNode->prev = NULL;
    
    if (*head != NULL) {
        (*head)->prev = newNode;
    }
    
    *head = newNode;
}

// Function to delete a node at the end of the DLL
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

// Function to delete a node at the beginning of the DLL
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

// Function to print the DLL in forward direction
void printForward(struct node* head) {
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse the DLL
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
        *head = temp->prev; // Update the head
    }
}

// Function to concatenate two DLLs
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

// Function to find the union of two DLLs
struct node* unionDLL(struct node* list1, struct node* list2) {
    struct node* result = NULL;

    // Insert elements of list1 into the result
    while (list1 != NULL) {
        append(&result, list1->data);
        list1 = list1->next;
    }

    // Insert elements of list2 into the result, skipping duplicates
    while (list2 != NULL) {
        if (!search(result, list2->data)) {
            append(&result, list2->data);
        }
        list2 = list2->next;
    }

    return result;
}

// Function to find the intersection of two DLLs
struct node* intersectionDLL(struct node* list1, struct node* list2) {
    struct node* result = NULL;

    // Iterate through list1
    while (list1 != NULL) {
        if (search(list2, list1->data)) {
            append(&result, list1->data);
        }
        list1 = list1->next;
    }

    return result;
}

// Function to search for a value in the DLL
int search(struct node* head, int key) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    // Append nodes to the end of the first DLL
    append(&head1, 50);
    append(&head1, 70);

    // Print the first DLL in forward direction
    printf("First DLL in forward direction:\n");
    printForward(head1);

    // Append nodes to the end of the second DLL
    append(&head2, 30);
    append(&head2, 40);

    // Print the second DLL in forward direction
    printf("Second DLL in forward direction:\n");
    printForward(head2);

    // Reverse the first DLL
    reverse(&head1);

    // Print the first DLL in reverse direction
    printf("First DLL in reverse direction:\n");
    printForward(head1);

    // Concatenate the second DLL to the end of the first DLL
    concatenate(&head1, head2);

    // Print the concatenated DLL
    printf("Concatenated DLL:\n");
    printForward(head1);

    // Find the union of the two DLLs
    struct node* unionResult = unionDLL(head1, head2);
    printf("Union of DLLs:\n");
    printForward(unionResult);

    // Find the intersection of the two DLLs
    struct node* intersectionResult = intersectionDLL(head1, head2);
    printf("Intersection of DLLs:\n");
    printForward(intersectionResult);

    // Search for a value in the DLL
    int searchValue = 30;
    if (search(head1, searchValue)) {
        printf("%d found in DLL.\n", searchValue);
    } else {
        printf("%d not found in DLL.\n", searchValue);
    }

    // Free the memory and clean up
    while (head1 != NULL) {
        struct node* temp = head
