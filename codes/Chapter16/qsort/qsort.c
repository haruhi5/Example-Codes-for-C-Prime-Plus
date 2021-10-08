#include <stdio.h>
#include<stdlib.h>
#include <math.h>

#define NUM 40
void fillarray(double arr[], int n);
void showarray(const double arr[], int n);
int mycomp(const void *p1, const void *p2);

int main(void)
{
    double vals[NUM];
    fillarray(vals,NUM);
    puts("Random list: ");
    showarray(vals,NUM);
    qsort(vals,NUM,sizeof(double),mycomp);
    puts("\nSorted list: ");
    showarray(vals,NUM);
    return 0;
}

void fillarray(double arr[], int n){
    int index;
    for(index=0; index<n; index++){
        arr[index] = (double)rand()/( (double)rand() + 0.1 );
    }
}

void showarray(const double arr[], int n){
    int index;
    for(index=0;index<n;index++){
        printf("%9.4f ",arr[index]);
        if(index%6==5)
            putchar('\n');
    }
    if(index%6!=0)
        putchar('\n'); // final line
}

int mycomp(const void *p1, const void *p2){
    const double *a1 = (const double *)p1;
    const double *a2 = (const double *)p2;
    if(*a1<*a2)
        return -1;
    else if(*a1==*a2)
        return 0;
    else
        return 1;
}