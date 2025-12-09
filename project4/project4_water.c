/*
Author: Nand Patel
Date: 10/08/2025
Reads current month's water usage and the last 10 months' usage.
Uses pointer arithmetic to find average and standard deviation.
Prints "Unusual usage." if current > avg + 2 * sd, else "Normal usage."
*/

#include <stdio.h>
#include <math.h>

#define SIZE 10

// find average
double average(double *usage, int n) {
    double sum = 0.0;
    double *p = usage;
    double *end = usage + n;
    for (; p < end; p++) {
        sum += *p;
    }
    return sum / n;
}

// find standard deviation
double standardDeviation(double *usage, double avg, int n) {
    double sumSq = 0.0;
    double *p = usage;
    double *end = usage + n;
    for (; p < end; p++) {
        double diff = *p - avg;
        sumSq += diff * diff;
    }
    return sqrt(sumSq / (n - 1));
}

int main(void) {
    double current, usage[SIZE];

    // input current month
    printf("Enter water usage for this month: ");
    scanf("%lf", &current);

    // input past usage
    printf("Enter water usage for the last 10 months: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%lf", &usage[i]);
    }

    // calculate average and deviation
    double avg = average(usage, SIZE);
    double sd = standardDeviation(usage, avg, SIZE);

    // check usage
    if (current > avg + 2 * sd)
        printf("Unusual usage.\n");
    else
        printf("Normal usage.\n");

    return 0;
}
