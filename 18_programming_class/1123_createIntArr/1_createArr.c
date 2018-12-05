#include<stdio.h>
#include<stdlib.h>
int* createIntArray(int, int);

int main(){
    int row = 4;
    int col = 5;
    int *arr;
    int i = 0;

    arr = createIntArray(row, col);

    for(i=0; i < row*col ; i++){
        arr[i]=i;
    }
    for(i=0; i < row*col ; i++){
        printf("%d ",*arr+i);
    }
    printf("\n");

    free(arr);

    for(i=0; i < row*col ; i++){
        printf("%d ",*arr+i);
    }
    printf("\n");
    return 0;
    
}

int* createIntArray(int row, int column){
    int *arr;
    arr = (int*) malloc(sizeof(int) * row * column);
    return arr;
}