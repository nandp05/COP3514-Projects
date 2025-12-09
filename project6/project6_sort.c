/* 
   Author: Nand Patel
   Date: 11/3/25
   Description: 
   Reads grocery items from an input file, stores them in an array of strings,
   sorts the items using selection sort, and writes the sorted list to output.txt.
*/

#include <stdio.h>
#include <string.h>

// Sorts an array of strings in ascending alphabetical order
void selection_sort(char items[][101], int n) {
    int i, j, minIndex;
    char temp[101];

    for(i = 0; i < n - 1; i++) {
        minIndex = i;
        for(j = i + 1; j < n; j++) {
            // Compare strings lexicographically
            if(strcmp(items[j], items[minIndex]) < 0) {
                minIndex = j;
            }
        }
        // Swap strings if needed
        if(minIndex != i) {
            strcpy(temp, items[i]);
            strcpy(items[i], items[minIndex]);
            strcpy(items[minIndex], temp);
        }
    }
}

int main(int argc, char *argv[]) {

    // Array of strings to hold up to 1000 items
    char items[1000][101];
    FILE *inFile, *outFile;
    int count = 0;

    // Must have 2 command line arguments
    if(argc != 3) return 1;

    // Open input file
    inFile = fopen(argv[1], "r");
    if(inFile == NULL) return 1;

    // Read each word from the file
    while(fscanf(inFile, "%100s", items[count]) == 1) {
        count++;
    }
    fclose(inFile);

    // Sort the items
    selection_sort(items, count);

    // Write sorted items to output.txt as required
    outFile = fopen("output.txt", "w");
    if(outFile == NULL) return 1;

    for(int i = 0; i < count; i++) {
        fprintf(outFile, "%s\n", items[i]);
    }

    fclose(outFile);
    return 0;
}