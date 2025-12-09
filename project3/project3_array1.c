/* 

Author: Nand Patel
Date: 06/10/2024
Write a program that checks both of the following conditions hold for a given array a1, a2, …, an. If the conditions hold, display “yes”, otherwise, display “no”.

a1 < a2 < … < an
For every i from 2 to n, ai isn’t divisible by ai-1.
Requirements

Follow the format of the examples below.
The program reads in the number of elements of the array, for example, 4, then read in the numbers in the array, for example, 3 6 8 9.
In the main function, declare the input array after reading in the number of elements of the array, then read in the elements.

*/

#include <stdio.h>

#define maxSize 100

int main(void) {
    int n; // number of elements in the array
    printf("Enter the length of the input array: ");
    scanf("%d", &n); // read the number of elements

    int arr[maxSize];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) { // read the elements
        scanf("%d", &arr[i]); // read each element
    }

    int valid = 1;  // flag to check if conditions are met
    for (int i = 1; i < n; i++) {  // check conditions from the second element
        if (arr[i-1] >= arr[i]) { // check if strictly increasing
            valid = 0;
            break;
        }
        if (arr[i] % arr[i-1] == 0) { // check divisibility condition
            valid = 0;
            break;
        }
    }

    if (valid)
        printf("Output: yes\n");
    else
        printf("Output: no\n");

    return 0;
}