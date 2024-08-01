#include "../include/headerA3.h"

void printOne(struct employee* headLL, int whichOne) {
    int i = 1;
    struct employee* curr = headLL;
    while(curr != NULL && i < whichOne) {
        curr = curr->nextEmployee;
        i++;
    }
    if(curr != NULL) {
        printf("\nEmployee id: %d\n", curr->empId);
        printf("First name: %s\n", curr->fname);
        printf("Last name: %s\n", curr->lname);
        printf("Dependents: ");
        for(int j = 0; j < curr->numDependents; j++) {
            printf("%s", curr->dependents[j]);
            if(j != curr->numDependents-1) {
                printf(", ");
            }
        }
        printf("\n");
    } else {
        printf("Invalid position entered.\n");
    }
}
