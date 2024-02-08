#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define MAX_WEIGHT 20
#define MAX_ITEMS 5

//Wasted 2 hours coding this approach but it turns out this approach is not optimal in our case. It is only optimal in a version of the problem
//where we are allowed to take every item as much as we would like. 
// :(


// void bubbleSort(double ratios[MAX_ITEMS], int values[MAX_ITEMS], int weights[MAX_ITEMS], int indices[MAX_ITEMS]){
//     //Bubble sort in decreasing order
//    for (int i = 0; i < MAX_ITEMS - 1; i++) {
//         for (int j = 0; j < MAX_ITEMS - i - 1; j++) {
//             if (ratios[j +1] > ratios[j]) {
//                 int temp1 = ratios[j];
//                 ratios[j] = ratios[j + 1];
//                 ratios[j + 1] = temp1;

//                 int temp2 = weights[j];
//                 weights[j] = weights[j + 1];
//                 weights[j + 1] = temp2;

//                 int temp3 = values[j];
//                 values[j] = values[j + 1];
//                 values[j + 1] = temp3;

//                 int temp4 = indices[j];
//                 indices[j] = indices[j + 1];
//                 indices[j + 1] = temp4;
//             }
//         }
//     }
// }
// int knapSack(int weights[MAX_ITEMS], int values[MAX_ITEMS], double ratios[MAX_ITEMS], int selected_bool[MAX_ITEMS]){
//     int result = 0;
//     int capacity = MAX_WEIGHT;
//     int indices[] = {0,1,2,3,4};

//     //Create a ratio array.
//     for (int i = 0; i < MAX_ITEMS; i++) {
//         ratios[i] = (double)values[i] / (double)weights[i]; //casting
//     }

//     //Bubble Sort the ratios in decreasing order.
//     bubbleSort(ratios,values,weights,indices);

//     //Greedily pick the items with the best ratios, if we don't have sufficent capacity, try the next item.
//     for(int i = 0; i < MAX_ITEMS; i++){
//         if(weights[i] <= capacity){
//             printf("ADDED TO KNAPSACK: %d\n", values[i]);
//             capacity-=weights[i];

//             //Fill the selected_bool array such that it indicates which items we have placed in our knapsack.
//             int index = indices[i];
//             selected_bool[index] = 1;

//             result+=values[i];
//             printf("CURRENT RESULT: %d\n", result);

//         }
//     }

//     return result;
// }


int knapSack(int weights[], int values[] , int selected_bool[]){
    //DP Approach
}

void enterItem(int weights[MAX_ITEMS], int values[MAX_ITEMS], char item){
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
    scanf("%d",&values[i]);
    scanf("%d",&weights[i]);


}


int main(){

    char items[] = {'A','B','C','D','E'};

    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    double ratios[MAX_ITEMS];
    int selected_bool[MAX_ITEMS];

    int maxProfit;

    char result[MAX_ITEMS]; //Needs to return the 

    int inputCount = 0;


    while (TRUE){
        char item;
        scanf(" %c", &item);

        switch(item){
            case 'A':
            case 'a':
                enterItem(weights,values,items[0]);
                inputCount++;
                break;
            case 'B':
            case 'b':     
                enterItem(weights,values,items[1]);
                inputCount++;
                break;
            case 'C':
            case 'c':
                enterItem(weights,values,items[2]);
                inputCount++;
                break;
            case 'D':
            case 'd':
                enterItem(weights,values,items[3]);
                inputCount++;
                break;
            case 'E':
            case 'e':
                enterItem(weights,values,items[4]);
                inputCount++;
                break;

            default:
                printf("Invalid Input. A valid item is A-E.");
                break;
        }

        if(inputCount >= 5){
               printf("WEIGHTS:");
                for (int i = 0; i < 5; i++) {
                    printf(" %d", weights[i]);
                }
                printf("\n");
                printf("VALUES:");
                for (int i = 0; i < 5; i++) {
                    printf(" %d", values[i]);
                }
                printf("\n");
            break; //Exit loop
        }
    }

    maxProfit = knapSack(weights,values,selected_bool);

    //Fill the result array properly.
    int temp;
    for(int i = 0; i < MAX_ITEMS; i++){
        if(selected_bool[i] == 1){
            result[temp] = items[i];
            temp++;
        }
    }

    printf("Maximum profit: %d\n", maxProfit);
    printf("Items that give the maximum profit: : %d\n", result); 

}