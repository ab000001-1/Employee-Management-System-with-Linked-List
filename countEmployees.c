#include "../include/headerA3.h"

int countEmployees(a3Emp *headLL) {
    int count = 0;
    while (headLL != NULL) {
        count++;
        headLL = headLL->nextEmployee;
    }
    return count;
}
