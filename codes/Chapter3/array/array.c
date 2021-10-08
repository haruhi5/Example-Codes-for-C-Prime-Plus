#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int main(){
    int const col = 3;
    int const row = 2;
    int grades[][col] = {
        {12,23,45},
        {64,78,89}
    };

    for(int i = 0; i < row;i++){
        for(int j = 0; j < col;j++){
            printf("%d",grades[i][j]);
        }
        printf("\n");
    }
    return 0;
}