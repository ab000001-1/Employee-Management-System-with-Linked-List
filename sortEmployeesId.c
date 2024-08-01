#include "../include/headerA3.h"

void sortEmployeesId(struct employee **headLL) {
    struct employee *current, *next, *prev, *temp;
    int sorted = 0;

    // check for empty list
    if (*headLL == NULL) {
        return;
    }

    while (!sorted) {
        sorted = 1;
        current = *headLL;
        prev = NULL;

        while (current != NULL && current->nextEmployee != NULL) {
            next = current->nextEmployee;

            if (current->empId > next->empId) {
                // swap the employees
                temp = next->nextEmployee;
                next->nextEmployee = current;
                current->nextEmployee = temp;

                if (prev == NULL) {
                    *headLL = next;
                } else {
                    prev->nextEmployee = next;
                }

                prev = next;
                sorted = 0;
            } else {
                prev = current;
                current = next;
            }
        }
    }
}
