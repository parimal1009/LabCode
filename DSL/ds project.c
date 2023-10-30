#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Coordinates {
    double latitude;
    double longitude;
};

struct Building {
    char name[100];
    char department[50];
    struct Coordinates location;
    struct Building* next;
};

struct Building* createBuilding(char name[], char department[], double latitude, double longitude) {
    struct Building* newBuilding = (struct Building*)malloc(sizeof(struct Building));
    strcpy(newBuilding->name, name);
    strcpy(newBuilding->department, department);
    newBuilding->location.latitude = latitude;
    newBuilding->location.longitude = longitude;
    newBuilding->next = NULL;
    return newBuilding;
}

void addBuilding(struct Building** head, struct Building* newBuilding) {
    if (*head == NULL) {
        *head = newBuilding;
    } else {
        struct Building* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newBuilding;
    }
}

struct Building* searchBuilding(struct Building* head, const char* keyword) {
    struct Building* current = head;
    while (current != NULL) {
        if (strcmp(current->department, keyword) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int main() {
    struct Building* head = NULL;

    addBuilding(&head, createBuilding("Medical Building", "Medical", 18.5541, 73.8194));
    addBuilding(&head, createBuilding("MBA Building", "MBA", 18.5539, 73.8190));
    addBuilding(&head, createBuilding("Engineering Building", "Engineering", 18.5537, 73.8198));

    char keyword[50];
    printf("Enter a department keyword (e.g., 'Medical', 'MBA', 'Engineering'): ");
    scanf("%s", keyword);

    struct Building* result = searchBuilding(head, keyword);

    int grid1[10][20];
    int grid2[10][20];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            grid1[i][j] = 0;
            grid2[i][j] = 0;
        }
    }

    int sitX = 5, sitY = 5;
    int sihX = 8, sihY = 12;
    int sibmX = 3, sibmY = 17;

    grid1[sitX][sitY] = 1;
    grid1[sihX][sihY] = 2;
    grid1[sibmX][sibmY] = 3;

    if (result != NULL) {
        if (strcmp(keyword, "Medical") == 0) {
            grid2[sitX][sitY] = 1;
        } else if (strcmp(keyword, "MBA") == 0) {
            grid2[sihX][sihY] = 2;
        } else if (strcmp(keyword, "Engineering") == 0) {
            grid2[sibmX][sibmY] = 3;
        }
    }

    printf("Text-Based Grid Representation of Buildings (Grid 1):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (grid1[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", grid1[i][j]);
            }
        }
        printf("\n");
    }

    printf("Text-Based Grid Representation of Buildings (Grid 2):\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (grid2[i][j] == 0) {
                printf(". ");
            } else {
                printf("%d ", grid2[i][j]);
            }
        }
        printf("\n");
    }

    if (result != NULL) {
        printf("Building Name: %s\n", result->name);
        printf("Department: %s\n", result->department);
        printf("Latitude: %lf\n", result->location.latitude);
        printf("Longitude: %lf\n", result->location.longitude);
    } else {
        printf("Building for the department '%s' not found.\n", keyword);
    }

    struct Building* current = head;
    while (current != NULL) {
        struct Building* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}