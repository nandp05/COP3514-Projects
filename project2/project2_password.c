/*
Author: Nand Patel
Date: 09/20/2023
Description: Program validates a password. It requires only letters or digits,
at least 8 characters, at least one uppercase letter, and at least one lowercase letter.
*/

#include <stdio.h>

int main() {
    char ch;
    int isValid = 1;
    int count = 0;
    int hasUpper = 0;
    int hasLower = 0; 
    // Initialize hasUpper and hasLower to 0

    printf("Enter input: ");
    ch = getchar(); // Read the first character

    while (ch != '\n') { // Continue until newline character
        if (!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')))  // Check for valid characters
            isValid = 0;
        if (ch >= 'A' && ch <= 'Z')
            hasUpper = 1;
        if (ch >= 'a' && ch <= 'z')
            hasLower = 1;
        count++;
        ch = getchar();
    }

    if (count < 8) isValid = 0; // Check for minimum length
    if (!hasUpper || !hasLower) isValid = 0;  // Check for at least one uppercase and one lowercase letter

    if (isValid)  // If all conditions are met
        printf("Valid");
    else
        printf("Invalid");

    return 0;
}
