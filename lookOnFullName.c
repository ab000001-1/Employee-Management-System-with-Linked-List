#include "../include/headerA3.h"

int lookOnFullName(struct employee *headLL, char whichName[100]) {
    int position = 1;  // start from the head of the LL
    while (headLL != NULL) {
        // combine the first and last name of the employee
        char fullName[MAX_LENGTH * 2];
        sprintf(fullName, "%s %s", headLL->fname, headLL->lname);
        // compare the given name with the employee's full name
        if (strcmp(fullName, whichName) == 0) {
            // the names match, return the position
            return position;
        }
        // move on to the next employee
        headLL = headLL->nextEmployee;
        position++;
    }
    // the name was not found in the LL, return -1
    return -1;
}
