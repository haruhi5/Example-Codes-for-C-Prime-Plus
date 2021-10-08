#include<stdio.h>

#define SIZE 10
int sum(const int arr[], int n);
// int sum(int * arr, int n);
int sump(const int *start, int *end);

int main(void) {

    int marbles[SIZE] = {20,10,5,39,4,16,19,26,31,20};
    long ans;

    ans = sum(marbles,SIZE);
    printf("The total number of marbles is %ld.\n", ans);
    printf("The size of marbles is %I64u bytes.\n",sizeof marbles); // suggest by compiler
    printf("The length of marbles is %I64d.\n",sizeof(marbles)/sizeof(int));
    printf("Why size of marbles %I64u / size of arr %I64u is not equal to the length of marbles %I64u?\n", sizeof marbles, sizeof &marbles[0], sizeof(marbles)/sizeof(int));
    printf("Because in sum(int arr[],...) the arr is the pointer of the first element of marbles.\n");
    
    ans = sump(marbles,marbles+SIZE);
    printf("The total number of marbles is %ld.\n", ans);
    return 0;
}

int sum(const int arr[], int n){
    // arr as address of array
    int i;
    int total = 0;
    for (i=0;i<n;i++){
        total+=arr[i];
    }
    printf("The size of array is %I64u bytes.\n",sizeof arr); // only type must use ()
    return total;

}

int sump(const int *start, int *end){
    // arr as address of array
    int total = 0;
    while(start < end){
        //total += *start;
        //start++;
        total += *start++;
        // (*start)++ change the value in arr[0] which is not correct in this program  
    }
    printf("The size of array is %I64u bytes.\n",sizeof start); // only type must use ()
    return total;

}