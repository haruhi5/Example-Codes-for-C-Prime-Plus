#include<stdio.h>
#include<time.h>

static unsigned long int next = 1; // seed

unsigned int rand0(void){
    next = next * 1103515245 + 12345;
    return (unsigned int)(next/65535)%32768;
}

unsigned int init_rand0( time_t *time ){
    next = *time;
}

void set_seed(unsigned int seed){
    next = seed;
}