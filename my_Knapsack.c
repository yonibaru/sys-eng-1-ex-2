#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define MAX_WEIGHT 20
#define MAX_ITEMS 5

//Wasted 2~ hours coding this approach but it turns out this approach is not optimal in our case. This is a solution to the fractional knapsack problem and 
// not the 0/1 knapsack problem (which is our problem).
// :(  give me some points plz <3


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
    //DP Bottom-up approach

    int result, temp;

    int DP[MAX_ITEMS + 1][MAX_WEIGHT + 1];

    //Since this array is local, the initial values of every cell are not 0 but rather garbage values. 
    //Therefore, we need to set every cell in the first row and column to 0.

    for (int i = 1; i <= MAX_ITEMS; i++){
        DP[i][0] = 0;
    }
    for (int j = 0; j <= MAX_WEIGHT; j++){
        DP[0][j] = 0;
    }

    //Generating our DP Table.
    for (int i = 1; i <= MAX_ITEMS; i++) {
        for (int j = 1; j <= MAX_WEIGHT; j++) {
            if (weights[i-1] > j) {
                DP[i][j] = DP[i-1][j];
            } else {
                int index = j - weights[i-1];

                int includeNext = DP[i-1][index] + values[i-1];
                int notIncludeNext = DP[i-1][j];

                if(notIncludeNext > includeNext){
                    DP[i][j] = notIncludeNext;
                } else{
                    DP[i][j] = includeNext;
                }
            }
        }
    }


    //Properly filling the selected_bool array.
    result = DP[MAX_ITEMS][MAX_WEIGHT];
    temp = MAX_WEIGHT;

    for (int i = MAX_ITEMS; i > 0 && result > 0; i--){
        if (result != DP[i - 1][temp]){
            selected_bool[i-1] = 1;
            temp -= weights[i-1];
            result -= values[i-1];
        } else {
            continue;
        }
    }

    return DP[MAX_ITEMS][MAX_WEIGHT]; 
}

void enterItem(int weights[MAX_ITEMS], int values[MAX_ITEMS], char item){
    int i;
    switch(item){
        case 'a':
            i = 0;
            break;
        case 'b':
            i = 1;
            break;
        case 'c':
            i = 2;
            break;
        case 'd':
            i = 3;
            break;
        case 'e':
            i = 4;
            break;
    }
    scanf("%d",&values[i]);
    scanf("%d",&weights[i]);


}


int main(){

    char items[] = {'a','b','c','d','e'};

    int weights[MAX_ITEMS];
    int values[MAX_ITEMS];
    int selected_bool[] = {0,0,0,0,0};

    int maxProfit,temp,flag;

    char result[] = {'\0','\0','\0','\0','\0'}; 

    int inputCount = 0; //I know this is 'abusable' but we're assuming our input is correct.


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
            break; //Exit while loop
        }
    }

    maxProfit = knapSack(weights,values,selected_bool);

    //Fill the result array properly as required, empty slots remain '\0' (NULL CHAR)
    temp = 0;
    flag = 0;
    for(int i = 0; i < MAX_ITEMS; i++){
        if(selected_bool[i] == 1){
            result[temp] = items[i];
            temp++;
        }
    }

    printf("Maximum profit: %d\n", maxProfit);
    // printf("Items that give the maximum profit: [");
    printf("Selected items:");
    for(int i = 0; i < MAX_ITEMS;i++){
        if(result[i] != '\0'){
            printf(" %c", result[i]);
            // if(flag == 1){
            //     printf(", %c", result[i]);
            // } else{
            //     printf("%c", result[i]);
            //     flag = 1;
            // }
        }

    }
    // printf("]\n");

}