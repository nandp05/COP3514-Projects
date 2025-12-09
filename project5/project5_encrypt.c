/*
Author: Nand Patel
Date: 10/21/25

This program encrypts a message using a date-based Caesar cipher.
Each letter in the message is shifted by a number of positions determined
by the digits of the provided date.


*/

#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

int read_line(char *str, int n){ // Reads a line of input into str, up to n characters
    int ch, i = 0;
    while((ch = getchar()) != '\n'){ // Read until newline
        if(i < n){ *str++ = ch; i++; }
    }
    *str = '\0';
    return i;
}

void encrypt(char *message, char *encryptedMessage, int *date, int n){ // Encrypts the message using the date-based Caesar cipher
    char *p = message; 
    char *e = encryptedMessage;
    int *d = date;
    int *dEnd = date + n;

    while(*p != '\0'){  // Process each character in the message
        char ch = *p;
        if(ch >= 'A' && ch <= 'Z'){
            int shift = *d;
            int off = ch - 'A';
            *e = (char)('A' + (off + shift) % 26);  // Encrypt uppercase letters
            d++; if(d == dEnd) d = date;
            p++; e++;
        }else if(ch >= 'a' && ch <= 'z'){ //   Encrypt lowercase letters
            int shift = *d;
            int off = ch - 'a';
            *e = (char)('a' + (off + shift) % 26);
            d++; if(d == dEnd) d = date;
            p++; e++;
        }else{  // Non-alphabetic characters remain unchanged
            *e = ch;
            p++; e++;
        }
    }
    *e = '\0';
}

int main(void){
    char message[MAX_LEN + 1]; // Buffer for the input message
    char encrypted[MAX_LEN + 1]; // Buffer for the encrypted message
    int date[8];

    printf("Enter the message: ");
    read_line(message, MAX_LEN);

    printf("Enter date in the format of 8 digits: ");
    for(int k = 0; k < 8; k++) scanf("%1d", &date[k]);

    encrypt(message, encrypted, date, 8); // Encrypt the message
    printf("%s\n", encrypted); // Print the encrypted message
    return 0;
}
