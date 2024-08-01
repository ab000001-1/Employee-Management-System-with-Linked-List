#include <stdio.h>
#include "../include/headerA3.h"

int main() {
    a3Emp * employees = NULL;

    int done = 0;
    while (!done) {
        printf("1. Add a new employee\n");
        printf("2. Print data of all employees\n");
        printf("3. Print employee data at position n in the LL\n");
        printf("4. View employee data based on empId\n");
        printf("5. View employee data based on full name\n");
        printf("6. Count number of employees\n");
        printf("7. Sort employee data in ascending order of empId\n");
        printf("8. Fire the nth employee\n");
        printf("9. Fire all employees\n");
        printf("Press anything else to quit.\n");
        printf("\nChoose a menu option: ");

        int input;
        scanf("%d", &input);
        
        if (input == 1) {
            recruitEmployee(&employees);
        } else if (input == 2) {
            printAll(employees);
        } else if (input == 3) {
            printf("\nEnter a position: ");
            scanf("%d", &input);
            printOne(employees, input);
        } else if (input == 4) {
            printf("\nEnter an employee ID: ");
            scanf("%d", &input);
            printOne(employees, lookOnId(employees, input));
        } else if (input == 5) {
            printf("\nEnter the full name of the employee: ");
            char fnInput[MAX_LENGTH], lnInput[MAX_LENGTH],fullName[MAX_LENGTH * 2 + 1];
            scanf("%s", fnInput);
            scanf("%s", lnInput);
            sprintf(fullName, "%s %s", fnInput, lnInput);
            printOne(employees, lookOnFullName(employees, fullName));
        } else if (input == 6) {
            printf("\nTotal number of employees = %d\n", countEmployees(employees));
        } else if (input == 7) {
            printf("\nAfter sorting, the employees are as follows: \n\n");
            sortEmployeesId(&employees);
            printAll(employees);
            printf("\n");
        } else if (input == 8) {
            printf("\nWhich employee do you wish to fire - enter a value between 1 and %d: ", countEmployees(employees));
            scanf("%d", &input);
            fireOne(&employees, input);
        } else if (input == 9) {
            fireAll(&employees);
        } else {
            done = 1;
        }
    }
    
   return 0;
}
