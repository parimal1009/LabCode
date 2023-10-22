#include <stdio.h>
#define v 4

void make(int matrix[v][v]){
    for(int i =0;i<v;i++){
        for(int j=0;j<v;j++){
            matrix[i][j]=0;
        }
    }
}

void print(int matrix[v][v]){
    for(int i =0;i<v;i++){
        for(int j=0;j<v;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void add_edge(int matrix[v][v],int from,int to,int *edge){
    matrix[from][to]=*edge;
    matrix[to][from]=*edge;
    (*edge)++;
}
int main() {
    
    int edge = 1;
    int matrix[v][v];
    make(matrix);
    print(matrix);
    add_edge(matrix,1,2,&edge);
    add_edge(matrix,3,1,&edge);
    print(matrix);
}