/*
  project1_storage.c
  Author: Nand Patel
  Date: 8/28/25

  This program essentailly calculates the total charge for renting a storage unit based on user imput. The prices are 	
  Size	First month	Monthly rate after first month	Per year (maximum)
1	5'x5'   unit    $0  $40	    $400
2	5'x10'  unit    $25 $50	    $500
3	10'x10' unit	$40	$100	$800
4	10'x15' unit	$60	$150	$1200
The user selectes the desired storage unit size and its tenure in months. The program then calculates and displays the total charge.
 
*/

#include <stdio.h>

int main(void) {
    int selection, months;
    int firstMonth = 0, monthlyRate = 0, maxYear = 0;  //initialize variables
    int totalCharge = 0;

    printf("Please select from four types of storage units: 1, 2, 3, and 4\n"); //prompt user for input
    printf("Enter storage selection:");
    if (scanf("%d", &selection) != 1) {
        printf("Invalid selection. Select from 1 to 4.\n");
        return 0;
    }
    if (selection < 1 || selection > 4) {
        printf("Invalid selection. Select from 1 to 4.\n");  //ensures valid input
        return 0;
    }

    printf("Enter months:");
    if (scanf("%d", &months) != 1 || months < 0) {
        printf("Invalid months.\n"); //invalid input check
        return 0;
    }

    if (selection == 1) {
        firstMonth = 0;  monthlyRate = 40;  maxYear = 400;//set rates based on user selection
    } else if (selection == 2) {
        firstMonth = 25; monthlyRate = 50;  maxYear = 500;
    } else if (selection == 3) {
        firstMonth = 40; monthlyRate = 100; maxYear = 800;
    } else { //selection == 4 
        firstMonth = 60; monthlyRate = 150; maxYear = 1200;
    }

    if (months == 0) {
        totalCharge = 0; //no charge 
    } else if (months <= 12) {
        totalCharge = firstMonth + (months - 1) * monthlyRate; //first month flat rate + monthly rate
        if (totalCharge > maxYear) totalCharge = maxYear;
    } else {
        int years = months / 12;
        int remMonths = months % 12; //calculates remaining months after full years
        totalCharge = years * maxYear;
        if (remMonths > 0) {
            int remCost = remMonths * monthlyRate; // no first-month flat
            if (remCost > maxYear) remCost = maxYear;
            totalCharge += remCost;
        }
    }

    printf("Charge($):%d\n", totalCharge); //display total charge
    return 0;
}
