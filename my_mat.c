#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define SIZE 10


void floydWarshal(int matrix[10][10], int dist[10][10]){

    //Copy matrix into dist.
    for(int i = 0; i < SIZE ; i++){
        for(int j = 0; j < SIZE; j++){
            //we need prepare our matrix accordingly.
            if(i != j && matrix[i][j] == 0){
                dist[i][j] = INT_MAX;
            } else{
                dist[i][j] = matrix[i][j];
            }
        }
    }

    //The Floyd-Warshall Algorithm
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && k != i && k != j && i != j) {
                        //We have to insure dist[k][j] and dist[i][k] are not individually equal to INT_MAX because summing them up could result in unexpected errors.
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }else{
                        continue;
                    }
                }
            }
        }

}

void enterMatrix(int matrix[10][10]){
    for(int i = 0;i < SIZE;i++){
        for(int j = 0;j < SIZE; j++){
            scanf("%d",&matrix[i][j]);
        }
    }
}

void pathExists(int dist[10][10]){
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);

    if(dist[i][j] == INT_MAX || i == j){
        printf("False\n");
    } else{
        printf("True\n");
    }

}

void shortestPath(int dist[10][10]){
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);
    if(dist[i][j] == INT_MAX || dist[i][j] == 0){
        printf("%d\n", -1);
    } else{
        printf("%d\n", dist[i][j]);
    }
}