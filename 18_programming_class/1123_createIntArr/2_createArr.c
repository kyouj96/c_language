#include<stdio.h>
#include<stdlib.h>
int* createIntArray(int, int);

int main(){
    int row = 4;
    int col = 5;
    int *a;
    int i = 0;
    int (*b)[5];
    a = createIntArray(row, col); 
    b = a;
    for(i=0; i < row*col ; i++){
        a[i]=i;
    }

    a[6]=100;
    b[2][2]=500;

    for(i=0; i < row*col ; i++){
        printf("%p : %d , %p : %d \n",a+i, *(a+i), &b[i/5][i%5], b[i/5][i%5]);
    }
    printf("\n");
    

    free(a);
    
    return 0;
}
int* createIntArray(int row, int column){
    int *arr;
    arr = (int*) malloc(sizeof(int) * row * column);
    return arr;
}
