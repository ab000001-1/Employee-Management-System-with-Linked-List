#include "../include/headerA3.h"

void fireAll(a3Emp **headLL) {
    char choice;
    printf("\nAre you sure you want to fire everyone: ");
    scanf(" %c", &choice);
    if (tolower(choice) == 'y') {
        a3Emp *currEmp = *headLL;
        while (currEmp != NULL) {
            a3Emp *temp = currEmp;
            currEmp = currEmp->nextEmployee;
           //free memory
            free(temp);
        }
        //reset to NULL
        *headLL = NULL; 
        printf("All fired. Linked list is now empty.\n\n");
    }
}
