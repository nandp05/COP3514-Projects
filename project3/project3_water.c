/*
Author: Nand Patel
Date: 06/10/2024

this program reads the current month's water usage and the past 10 months' usage, then determines if the current usage is unusual based on statistical analysis.
An unusual usage is defined as being more than two standard deviations above the average of the past 10 months' usage.
If it is unusual, the program outputs "Unusual usage.", otherwise it outputs "Normal usage.".


*/

#include <stdio.h>
#include <math.h>
#define SIZE 10  // number of past months


/*
class which contains functions to calculate average and standard deviation
average and standard deviation functions are defined below
*/
double average(double usage[], int n) {   // function to calculate average
    double sum = 0.0;
    for (int i = 0; i < n; i++) { // sum all usage values
        sum += usage[i];  // accumulate sum
    }
    return sum / n;  // return average
}

double standard_deviation(double usage[], double avg, int n) {  // function to calculate standard deviation
    double sum = 0.0;
    for (int i = 0; i < n; i++) {  // calculate sum of squared differences from the mean
        sum += (usage[i] - avg) * (usage[i] - avg);  // accumulate squared differences
    }
    return sqrt(sum / (n - 1));  // return standard deviation
}

int main(void) {
    double current, usage[SIZE]; // current month's usage and array for past 10 months' usage
    printf("Enter water usage for this month:");
    scanf("%lf", &current);

    printf("Enter water usage for the last 10 months: ");  // prompt for past 10 months' usage
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &usage[i]);
    }

    double avg = average(usage, SIZE);// calculate average
    double sd = standard_deviation(usage, avg, SIZE);// calculate average and standard deviation

    if (current > avg + 2 * sd) // check if current usage is more than two standard deviations above the average
        printf("Unusual usage.\n");
    else
        printf("Normal usage.\n");

    return 0;
}
