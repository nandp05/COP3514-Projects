/** 
 * Author: Nand Patel
 * Date: 11/05/25
 * 
 * This program reads student data from a CSV file, assigns levels based on points,
 * and writes the updated data to a new CSV file.
 * Level assignment criteria:
 * Level 1: 0-50 points
 * Level 2: 51-95 points
 * Level 3: 96+ points
 * Input file format: first name, last name, points
 * Output file format: first name, last name, points, level
 * Example input line: John, Doe, 85
 * Example output line: John, Doe, 85, 2
 * 
 * 
 * 
*/

#include <stdio.h>

#define MAX_STUDENTS 1000
#define MAX_STR_LEN 100
// Define a structure to hold student data
struct Student {
    char firstName[MAX_STR_LEN + 1];
    char lastName[MAX_STR_LEN + 1];
    int points;
    int level;
};
// Function prototypes
int readLine(char str[], int n);
void assignLevel(struct Student list[], int n); //  Assign levels based on points
// Main function
int main(void) {
    char fileName[256];
    struct Student students[MAX_STUDENTS];
    int count = 0;
    FILE *inFile, *outFile; // File pointers

    printf("Enter file name: ");
    readLine(fileName, 255);

    inFile = fopen(fileName, "r");
    if (inFile == NULL) { // Check if file opened successfully
        printf("Error opening input file\n");
        return 1;
    }

    while (count < MAX_STUDENTS && 
           fscanf(inFile, "%[^,], %[^,], %d\n", 
                  students[count].firstName,
                  students[count].lastName,
                  &students[count].points) == 3) {
        count++;
    }
    fclose(inFile);

    assignLevel(students, count);

    outFile = fopen("result.csv", "w");// Open output file
    if (outFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }

    for (int i = 0; i < count; i++) { // Write updated data to output file
        fprintf(outFile, "%s, %s, %d, %d\n",
                students[i].firstName,
                students[i].lastName,
                students[i].points,
                students[i].level);
    }

    fclose(outFile);
    printf("Output file: result.csv\n");
    return 0;
}

int readLine(char str[], int n) { // Read a line of input
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

void assignLevel(struct Student list[], int n) {
    for (int i = 0; i < n; i++) { // Assign levels based on points
        int pts = list[i].points;
        if (pts >= 0 && pts <= 50)
            list[i].level = 1;
        else if (pts >= 51 && pts <= 95)
            list[i].level = 2;
        else
            list[i].level = 3;
    }
}
