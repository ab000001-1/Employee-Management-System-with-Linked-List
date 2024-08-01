#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId) {
    int position = 1;
    struct employee * current = headLL;

    while (current != NULL) {
         
        if (current->empId == whichEmpId) {
            // Employee found, return the position
            return position;
        }
        current = current->nextEmployee;
        position++;
    }

    // Employee not found, return -1
    return -1;
}
