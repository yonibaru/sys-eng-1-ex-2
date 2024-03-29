
#include <stdio.h>
#include "my_mat.h"
#include "my_mat.c"

#define SIZE 10


int main(){

    int mainMatrix[SIZE][SIZE];
    int dist[SIZE][SIZE]; //distance matrix, used for our Floyd-Warshall Algorithm which helps us in implementing 2 functions.

    char currentFunction;

    while (TRUE){
        scanf(" %c", &currentFunction);
 
        switch (currentFunction){
            case 'A':
                enterMatrix(mainMatrix);
                floydWarshal(mainMatrix,dist);

                //  int testMatrix[SIZE][SIZE] = {
                //     {0, 37, 19, 24, 26, 11, 29, 41, 22, 41},
                //     {37, 0, 28, 25, 31, 38, 14, 6, 0, 1},
                //     {19, 28, 0, 36, 42, 12, 39, 22, 39, 22},
                //     {24, 25, 36, 0, 16, 23, 26, 5, 12, 38},
                //     {26, 31, 42, 16, 0, 31, 23, 39, 31, 9},
                //     {11, 38, 12, 23, 31, 0, 48, 30, 5, 1},
                //     {29, 14, 39, 26, 23, 48, 0, 46, 6, 31},
                //     {41, 6, 22, 5, 39, 30, 46, 0, 29, 40},
                //     {22, 0, 39, 12, 31, 5, 6, 29, 0, 11},
                //     {41, 1, 22, 38, 9, 1, 31, 40, 11, 0}
                //     };
                // floydWarshal(testMatrix,dist);

                break;
            case 'B':
                pathExists(dist);
                break;
            case 'C':
                shortestPath(dist);
                break;
            case 'D':
                return 0;
            default:
                break;
        }
    }
}
