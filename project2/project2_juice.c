/*
Author: Nand Patel
Date: 09/20/2023
Description: This program simulates a juice vending machine.it takes nickels, dimes, quarters, and returns change if necessary.
It also checks for invalid coins and selections based on cup size.
*/

#include <stdio.h>

#define smallCup 75
#define largeCup 125

int main(void) {
    int coin, totalAmount = 0, change, selection; //initialize variables

    do { //loop to accept coins until 0 is entered
        printf("Insert coins: ");
        scanf("%d", &coin);
        if (coin != 0 && coin != 5 && coin != 10 && coin != 25) {
            printf("Invalid coin. Please enter 0, 5, 10, or 25.\n");
            continue;
        }
        totalAmount += coin;
    } while (coin != 0); //end loop when 0 is entered

    printf("Please select 1 for a small cup and 2 for a large cup: "); //prompt
    scanf("%d", &selection);

    switch (selection) { //handle selection and calculate change
        case 1:
            if (totalAmount >= smallCup) { //check if enough money for small cup
                printf("Collect your juice and enjoy!\n"); 
                change = totalAmount - smallCup; //calculate change
                if (change > 0)
                    printf("Your change is %d cents. Collect your change at the bottom.\n", change);
            } else {
                printf("Insufficient amount.\n");
                printf("Your change is %d cents. Collect your change at the bottom.\n", totalAmount);
            }
            break;
        case 2:
            if (totalAmount >= largeCup) {  //check if enough money for large cup
                printf("Collect your juice and enjoy!\n");
                change = totalAmount - largeCup; //calculate change
                if (change > 0)
                    printf("Your change is %d cents. Collect your change at the bottom.\n", change);
            } else {
                printf("Insufficient amount.\n");
                printf("Your change is %d cents. Collect your change at the bottom.\n", totalAmount);
            }
            break;
        default:
            printf("Invalid selection.\n");
            printf("Your change is %d cents. Collect your change at the bottom.\n", totalAmount);
            break;
    }

    return 0;
}
