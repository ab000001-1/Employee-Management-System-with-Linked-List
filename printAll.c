#include "../include/headerA3.h"

void printAll(struct employee *headLL) {
    struct employee *current = headLL;
    int count = 0;

    // Traverse the linked list and print the data of each employee
    while (current != NULL) {
        count++;
        printf("\nEmployee # %d:\n", count);
        printf("Employee id: %d\n", current->empId);
        printf("First name: %s\n", current->fname);
        printf("Last name: %s\n", current->lname);
        printf("Dependents [%d]: ", current->numDependents);
        for (int i = 0; i < current->numDependents; i++) {
            printf("%s", current->dependents[i]);
            if (i != current->numDependents - 1) {
                printf(", ");
            }
        }
        printf("\n");
        current = current->nextEmployee;
    }

    // Print the total number of employees in the linked list
    printf("\nCurrently, there are %d employees.\n", count);
}
