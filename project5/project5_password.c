/*
Author: Nand Patel
Date: 10/21/25

This program checks if the provided password meets the following criteria:
1. At least 8 characters long
2. Contains at least one uppercase letter
3. Contains at least one lowercase letter
4. Contains only alphanumeric characters (letters and digits)


*/

#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc != 2){
        printf("Invalid number of arguments\n");
        return 0;
    }

    // Validate password
    char *p = argv[1];
    int isValid = 1;
    int count = 0;
    int hasUpper = 0;
    int hasLower = 0;

    while(*p != '\0'){ // Iterate through each character
        char ch = *p;
        if(!((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))) isValid = 0;
        if(ch >= 'A' && ch <= 'Z') hasUpper = 1;
        if(ch >= 'a' && ch <= 'z') hasLower = 1;
        count++;
        p++;
    }

    if(count < 8) isValid = 0;
    if(!hasUpper || !hasLower) isValid = 0;

    if(isValid) printf("Valid\n"); else printf("Invalid\n"); // Output result
    return 0;
}
