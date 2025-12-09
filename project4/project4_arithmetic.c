/*
Author: Nand Patel
Date: 10/08/2025

Checks whether a user-entered integer sequence is an arithmetic sequence.
Uses pointer arithmetic in isArithmeticSequence() (no [] and no index variables).
*/

#include <stdio.h>

int isArithmeticSequence(int *sequence, int n) { 
    if (n <= 2) return 1;

    int *p = sequence;
    int *q = sequence + 1;
    int diff = *q - *p;

    for (p = sequence + 2; p < sequence + n; p++) { // start from the third element
        if ((*p - *(p - 1)) != diff) {
            return 0;
        }
    }
    return 1;
}

int main(void) { 
    int n; 
    printf("Enter length of the sequence: "); 
    scanf("%d", &n);

    if (n <= 0) return 0;

    int arr[n];
    printf("Enter numbers of the sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isArithmeticSequence(arr, n))
        printf("yes\n");
    else
        printf("no\n");

    return 0;
}
