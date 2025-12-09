/**project9_tutors.c
author: nand patel
 date: 11/24/25

this program manages a linked list of tutors, allowing users to add, delete, search, and print tutor information.
new tutors are added in sorted order based on last and first names.
this is based off project 8tutors.c with added functionality for sorted insertion and deletion.

 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31
#define EMAIL_LEN 51

struct tutor {
    char last_name[NAME_LEN];
    char first_name[NAME_LEN];
    char email[EMAIL_LEN];
    int pref1;
    int pref2;
    int pref3;
    struct tutor *next;
};

// function prototypes
struct tutor *add_to_list(struct tutor *list);
struct tutor *delete_from_list(struct tutor *list);
void search_list(struct tutor *list);
void print_list(struct tutor *list);

static int compare_tutors(const struct tutor *a, const struct tutor *b)
{
    int c = strcmp(a->last_name, b->last_name);
    if (c != 0) {
        return c;
    }
    return strcmp(a->first_name, b->first_name);
}

int main(void)
{
    struct tutor *list = NULL;
    char code;

    // *** MUST MATCH EXACTLY ***
    printf("Operation Code: a for adding to the list, s for searching, d for deleting from the list, p for printing the list; q for quit.\n");

    for (;;) {
        printf("Enter operation code: ");
        if (scanf(" %c", &code) != 1) {
            break;
        }

        switch (code) {
            case 'a':
                list = add_to_list(list);
                break;
            case 'd':
                list = delete_from_list(list);
                break;
            case 's':
                search_list(list);
                break;
            case 'p':
                print_list(list);
                break;
            case 'q':
                return 0;
            default:
                printf("Illegal code\n");
                break;
        }
    }

    return 0;
}

// add tutor in sorted order by last, then first name
struct tutor *add_to_list(struct tutor *list)
{
    struct tutor *new_node;
    struct tutor *cur;
    struct tutor *prev;

    new_node = malloc(sizeof(struct tutor));
    if (new_node == NULL) {
        printf("malloc failed\n");
        return list;
    }

    printf("Enter last name: ");
    scanf("%s", new_node->last_name);

    printf("Enter first name: ");
    scanf("%s", new_node->first_name);

    printf("Enter email address: ");
    scanf("%s", new_node->email);

    printf("Enter preferences: ");
    scanf("%d%d%d", &new_node->pref1, &new_node->pref2, &new_node->pref3);
    printf("\n");  // newline so next "Enter operation code:" starts on new line

    new_node->next = NULL;

    if (list == NULL) {
        return new_node;
    }

    prev = NULL;
    cur = list;

    // move while current <= new node (so duplicates stay before new one)
    while (cur != NULL && compare_tutors(cur, new_node) <= 0) {
        prev = cur;
        cur = cur->next;
    }

    if (prev == NULL) {
        new_node->next = list;
        list = new_node;
    } else {
        new_node->next = cur;
        prev->next = new_node;
    }

    return list;
}

// delete tutor that matches last, first, and email
struct tutor *delete_from_list(struct tutor *list)
{
    char last[NAME_LEN];
    char first[NAME_LEN];
    char email[EMAIL_LEN];

    struct tutor *cur;
    struct tutor *prev;

    if (list == NULL) {
        printf("tutor does not exist\n");
        return NULL;
    }

    printf("Enter last name: ");
    scanf("%s", last);

    printf("Enter first name: ");
    scanf("%s", first);

    printf("Enter email address: ");
    scanf("%s", email);

    prev = NULL;
    cur = list;

    while (cur != NULL) {
        if (strcmp(cur->last_name, last) == 0 &&
            strcmp(cur->first_name, first) == 0 &&
            strcmp(cur->email, email) == 0) {
            break;
        }
        prev = cur;
        cur = cur->next;
    }

    if (cur == NULL) {
        printf("tutor does not exist\n");
        return list;
    }

    if (prev == NULL) {
        list = cur->next;
    } else {
        prev->next = cur->next;
    }

    free(cur);
    printf("tutor deleted\n");

    return list;
}

// search by last name and print matches
void search_list(struct tutor *list)
{
    char last[NAME_LEN];
    struct tutor *p;
    int found = 0;

    printf("Enter last name: ");
    scanf("%s", last);

    for (p = list; p != NULL; p = p->next) {
        if (strcmp(p->last_name, last) == 0) {
            printf("%-12s %-12s %-30s %5d %5d %5d\n",
                   p->last_name, p->first_name, p->email,
                   p->pref1, p->pref2, p->pref3);
            found = 1;
        }
    }

    if (!found) {
        printf("tutor does not exist\n");
    } else {
        printf("\n");  // blank line after results
    }
}

// print all tutors
void print_list(struct tutor *list)
{
    struct tutor *p;

    for (p = list; p != NULL; p = p->next) {
        printf("%-12s %-12s %-30s %5d %5d %5d\n",
               p->last_name, p->first_name, p->email,
               p->pref1, p->pref2, p->pref3);
    }

    printf("\n");  // blank line after list
}
