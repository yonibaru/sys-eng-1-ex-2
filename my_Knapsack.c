#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define MAX_WEIGHT 20
#define MAX_ITEMS 5

void bubbleSort(int ratios[]){

}

void enterItem(int weights[], int values[], char item){
    int i;
    switch(item){
        case 'A':
            i = 0;
            break;
        case 'B':
            i = 1;
            break;
        case 'C':
            i = 2;
            break;
        case 'D':
            i = 3;
            break;
        case 'E':
            i = 4;
            break;
    }
    scanf("%d",values[i]);
    scanf("%d",weights[i]);

}

int knapSack(int weights[], int values[], double ratios[], int selected_bool[]){
    int result;

    for (int i = 0; i < MAX_ITEMS; i++) {
        ratios[i] = (double)values[i] / (double)weights[i]; //casting
    }

    //Bubble Sort the ratios in decreasing order.
    //Greedily pick the items with the best ratios, if we don't have sufficent space, try the next item.
    //Fill the selected_bool array such that it indicates which items we have placed in our knapsack.
    //Return the value in the knapsack (iterate over the values array using selected bool and append to resutl)



}

int main(){
    char items = {'A','B','C','D','E'};
    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    double ratios[MAX_ITEMS];
    int maxProfit;
    int result[MAX_ITEMS]; //Needs to return the 

    while (TRUE){
        char item;
        scanf(" %c", &item);

        switch(item){
            case 'A':
            case 'a':
                enterItem(weights,values,"A");
                break;
            case 'B':
            case 'b':     
                enterItem(weights,values,"B");
                break;
            case 'C':
            case 'c':
                enterItem(weights,values,"C");
                break;
            case 'D':
            case 'd':
                enterItem(weights,values,"D");
                break;
            case 'E':
            case 'e':
                enterItem(weights,values,"E");
                break;

            default:
                printf("Invalid Input. A valid item is A-E.");
                break;
        }

    }
    printf("Maximum profit: %d", maxProfit);
    printf("Items that give the maximum profit: : %d", result); //CHECK how to properly print the array..

}