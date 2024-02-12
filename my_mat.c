#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

#define SIZE 10

//THIS IS NOT A DIRECTED GRAPH!!!!! UNDIRECTED

void floydWarshal(int matrix[10][10], int dist[10][10]){

    //Copy matrix into dist.
    for(int i = 0; i < SIZE ; i++){
        for(int j = 0; j < SIZE; j++){
            dist[i][j] = matrix[i][j];
        }
    }

    //The Floyd-Warshall Algorithm
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int k = 0; k < SIZE; k++) {
                    if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k] != INT_MAX && dist[k][j] != INT_MAX){
                        //We have to insure dist[k][j] and dist[i][k] are not individually equal to INT_MAX because summing them up could result in unexpected errors.
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

}

void enterMatrix(int matrix[10][10]){
    for(int i = 0;i< SIZE;i++){
        for(int j = 0;j < SIZE; j++){
            scanf("%d",&matrix[i][j]);

            // We are going to use the Floyd-Warshall Algorithm, so we need prepare our matrix accordingly.
            if(i != j && matrix[i][j] == 0){
                matrix[i][j] = INT_MAX;
            }
        }
    }

}

void pathExists(int matrix[10][10]){
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);

    if(matrix[i][j] != INT_MAX){
        printf("True\n");
    } else{
        printf("False\n");
    }

}

void shortestPath(int matrix[10][10]){
    int i,j;
    scanf("%d",&i);
    scanf("%d",&j);
    if(matrix[i][j] == INT_MAX){
        printf("%d\n", -1);
    } else{
        printf("%d\n", matrix[i][j]);
    }
}