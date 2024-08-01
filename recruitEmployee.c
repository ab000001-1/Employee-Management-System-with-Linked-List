#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL) {
    char fname[MAX_LENGTH], lname[MAX_LENGTH], dependent[MAX_LENGTH];
    int empId, sum = 0, len, moreDependents = 1;
    a3Emp *newEmp, *temp;

    // Enter first name and last name
    printf("\nEnter the first name of the employee: ");
    scanf("%s", fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", lname);

    // Calculate employee ID
    len = strlen(lname);
    for (int i = 0; i < strlen(fname); i++) {
        sum += (int)fname[i];
    }
    empId = sum + len;

    // Check if employee ID already exists in the linked list
    while (lookOnId(*headLL, empId) != -1) {
        empId += (rand() % 999) + 1;
    }

    // Create a new employee node and add it to the end of the linked list
    newEmp = (a3Emp*)malloc(sizeof(a3Emp));
    strcpy(newEmp->fname, fname);
    strcpy(newEmp->lname, lname);
    newEmp->empId = empId;
    newEmp->numDependents = 0;
    newEmp->dependents = NULL;
    newEmp->nextEmployee = NULL;

    if (*headLL == NULL) {
        *headLL = newEmp;
    } else {
        temp = *headLL;
        while (temp->nextEmployee != NULL) {
            temp = temp->nextEmployee;
        }
        temp->nextEmployee = newEmp;
    }

    // Enter dependent names
    while (moreDependents) {
        printf("\nEnter name of dependent# %d: ", newEmp->numDependents + 1);
        scanf("%s", dependent);

        // Add dependent name to the employee's list of dependents
        newEmp->dependents = (char**)realloc(newEmp->dependents, (newEmp->numDependents + 1) * sizeof(char*));
        newEmp->dependents[newEmp->numDependents] = (char*)malloc((strlen(dependent) + 1) * sizeof(char));
        strcpy(newEmp->dependents[newEmp->numDependents], dependent);
        newEmp->numDependents++;

        // Check if there are more dependents to add
        printf("Do you have any more dependents? ");
        char answer;
        scanf(" %c", &answer);
        if (tolower(answer) == 'n') {
            moreDependents = 0;
        }
    }

    // Print employee information and menu options
    printf("\nYou have %d dependents.\n", newEmp->numDependents);
    printf("\nYour computer-generated empId is %d\n", newEmp->empId);
}
