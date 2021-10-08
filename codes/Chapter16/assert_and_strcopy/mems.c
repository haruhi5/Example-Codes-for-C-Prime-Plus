#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 10

void show_array(const int arr[], int n);
// it's not _STATIC_ASSERT ?
//#define NDBUG
_Static_assert( (sizeof(double) == 2*sizeof(int)), "Double is not twice int size!");
//_Static_assert( (sizeof(double) != 2*sizeof(int)), "Double is twice int size!");

int main(void) {

    int values[SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int target[SIZE];
    double curious[SIZE/2] = {2.0,2.0e5,2.0e10,2.0e20,5.0e30};
    
    puts("memcpy() used: ");
    puts("values (original data): ");
    show_array(values,SIZE);
    memcpy(target,values,sizeof(int)*SIZE);
    puts("target (copy of data): ");
    show_array(target,SIZE);

    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values+2,values,5*sizeof(int));
    puts("values -- elements 0-4 copied to 2-6");
    show_array(values,SIZE);

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target,curious,SIZE*sizeof(double)/2);
    puts("target -- 5 doubles into 10 int positions");
    show_array(target+5,SIZE/2);

    return 0;
}

void show_array(const int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    putchar('\n');
}