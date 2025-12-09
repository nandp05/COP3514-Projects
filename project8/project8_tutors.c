/*
Author: Nand Patel
Date: 11/17/25

the purpose of this program is to manage a list of tutors using a linked list data structure.
it allows users to add tutors, search for tutors based on their preferences, print the list of tutors,
and clear the list when done.
it includes functions for reading input, adding tutors to the list, searching the list, printing the list, and clearing the list from memory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 30
#define EMAIL_LEN 50

typedef struct Tutor {  // structure to hold tutor information
    char lastName[NAME_LEN + 1];
    char firstName[NAME_LEN + 1];
    char emailAddress[EMAIL_LEN + 1];
    int preferences[3];
    struct Tutor *next;
} Tutor;

int read_line(char str[], int n);  // function prototype for reading a line of input

Tutor *add_to_list(Tutor *tutorList); 
void search_list(Tutor *tutorList);
void print_list(Tutor *tutorList);
void clear_list(Tutor *tutorList);

int main(void) { // main function
    char operationCode;
    Tutor *tutorList = NULL;

    printf("Operation Code: a for adding to the list, s for searching, p for printing the list; q for quit.\n"); // display operation codes

    for (;;) {  
        printf("Enter operation code: ");
        if (scanf(" %c", &operationCode) != 1) {
            break;
        }
        while (getchar() != '\n') { 
        }

        if (operationCode == 'a') {  // add tutor
            tutorList = add_to_list(tutorList);
        } else if (operationCode == 's') {
            search_list(tutorList);
        } else if (operationCode == 'p') {
            print_list(tutorList);
        } else if (operationCode == 'q') {
            clear_list(tutorList);
            return 0;
        } else {
            printf("Illegal code\n");
        }
    }

    clear_list(tutorList);  
    return 0;
}

Tutor *add_to_list(Tutor *tutorList) {  // function to add a tutor to the list
    char lastName[NAME_LEN + 1];
    char firstName[NAME_LEN + 1];
    char emailAddress[EMAIL_LEN + 1];
    int p0, p1, p2;

    Tutor *currentTutor; // pointer to traverse the list
    Tutor *newTutor;

    printf("Enter last name: ");  
    read_line(lastName, NAME_LEN);

    printf("Enter first name: ");  
    read_line(firstName, NAME_LEN);

    printf("Enter email address: ");  
    read_line(emailAddress, EMAIL_LEN);

    printf("Enter preferences: ");  
    if (scanf("%d %d %d", &p0, &p1, &p2) != 3) {
        while (getchar() != '\n') {
        }
        return tutorList;
    }
    while (getchar() != '\n') {  // clear input buffer
    }

    currentTutor = tutorList; // check for duplicates
    while (currentTutor != NULL) {  
        if (strcmp(currentTutor->lastName, lastName) == 0 &&
            strcmp(currentTutor->emailAddress, emailAddress) == 0) {
            printf("tutor already exists.\n\n");  // match expected output (with period and blank line)
            return tutorList;
        }
        currentTutor = currentTutor->next; // move to next tutor
    }

    newTutor = malloc(sizeof(Tutor));   // allocate memory for new tutor
    if (newTutor == NULL) {
        return tutorList;
    }

    strcpy(newTutor->lastName, lastName);
    strcpy(newTutor->firstName, firstName);
    strcpy(newTutor->emailAddress, emailAddress);
    newTutor->preferences[0] = p0;
    newTutor->preferences[1] = p1;
    newTutor->preferences[2] = p2;
    newTutor->next = NULL;

    if (tutorList == NULL) {  // if list is empty, new tutor becomes the first tutor
        printf("\n");         // newline after this add (to separate from next "Enter operation code:")
        return newTutor;
    }

    currentTutor = tutorList;
    while (currentTutor->next != NULL) {  // traverse to the end of the list
        currentTutor = currentTutor->next;
    }
    currentTutor->next = newTutor;

    printf("\n");  // newline after this add (to separate from next "Enter operation code:")
    return tutorList;
}

void search_list(Tutor *tutorList) {  // function to search for tutors based on level preference
    char levelInput[20];
    int levelIndex = -1;
    int found = 0;
    Tutor *currentTutor;

    printf("Enter level: ");  
    read_line(levelInput, 20);

    if (strcmp(levelInput, "elementary") == 0) {
        levelIndex = 0;
    } else if (strcmp(levelInput, "middle") == 0) {
        levelIndex = 1;
    } else if (strcmp(levelInput, "high") == 0) {
        levelIndex = 2;
    }

    if (levelIndex == -1) {  
        printf("not found\n\n");  // extra blank line after not found
        return;
    }

    currentTutor = tutorList;  // traverse the list to find matching tutors
    while (currentTutor != NULL) {
        if (currentTutor->preferences[levelIndex] == 1) {
            printf("%-12s%-12s%-30s\n",
                   currentTutor->lastName,
                   currentTutor->firstName,
                   currentTutor->emailAddress);
            found = 1;
        }
        currentTutor = currentTutor->next;
    }

    if (!found) {  
        printf("not found\n\n");  // not found with blank line
    } else {
        printf("\n");             // blank line after listing tutors
    }
}

void print_list(Tutor *tutorList) {  // function to print the list of tutors
    Tutor *currentTutor = tutorList;

    while (currentTutor != NULL) {
        printf("%-12s%-12s%-30s%5d%5d%5d\n",
               currentTutor->lastName,
               currentTutor->firstName,
               currentTutor->emailAddress,
               currentTutor->preferences[0],
               currentTutor->preferences[1],
               currentTutor->preferences[2]);
        currentTutor = currentTutor->next;
    }

    printf("\n"); // blank line after printing list (matches expected output)
}

void clear_list(Tutor *tutorList) {  // function to clear the list from memory
    Tutor *currentTutor;

    while (tutorList != NULL) {
        currentTutor = tutorList;
        tutorList = tutorList->next;
        free(currentTutor);
    }
}

int read_line(char str[], int n) {  // function to read a line of input
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {  
        if (i < n) {
            str[i++] = (char)ch;
        }
    }
    str[i] = '\0';
    return i;
}
