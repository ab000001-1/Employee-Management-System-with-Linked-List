#include "../include/headerA3.h"

void fireOne(a3Emp** headLL, int whichOne) {
    // Check if the list is empty
    if (*headLL == NULL) {
        printf("There are no employees to fire.\n");
        return;
    }

    // Check if the requested employee exists
    if (whichOne < 1 || whichOne > countEmployees(*headLL)) {
        printf("Invalid employee number.\n");
        return;
    }

    a3Emp* temp = *headLL;

    // Special case for deleting the head node
    if (whichOne == 1) {
        *headLL = temp->nextEmployee;
        printf("Employee [Id: %d] fired.\n", temp->empId);
        free(temp);
        return;
    }

    // Traverse the linked list to find the node before the requested employee
    for (int i = 1; i < whichOne - 1; i++) {
        temp = temp->nextEmployee;
    }

    // Delete the requested employee node
    a3Emp* toDelete = temp->nextEmployee;
    temp->nextEmployee = toDelete->nextEmployee;
    printf("Employee [Id: %d] fired.\n", toDelete->empId);
    free(toDelete);
}
