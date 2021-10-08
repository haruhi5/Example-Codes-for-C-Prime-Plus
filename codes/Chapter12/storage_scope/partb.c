#include<stdio.h>

extern int count; // external link
static int total = 0;

void accumaulate(int k);

void accumaulate(int k){
    static int subtotal = 0;

    if(k<=0){
        printf("loop cycle: %d\n",count);
        printf("subtotal: %d; total: %d\n",subtotal,total);
        subtotal = 0;
    }
    else{
        subtotal += k;
        total += k;
    }
}
