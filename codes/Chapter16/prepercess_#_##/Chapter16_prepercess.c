#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

#define NAME(n) x##n                           // combine
#define PRINT(n) printf("x" #n "= %d\n", x##n) // replace as a string: stringizing
#define PR(x, ...) printf("Message" #x ": " __VA_ARGS__)

int main(void)
{
    int NAME(1) = 2;
    //PRINT(NAME(1));
    PRINT(1);
    PR(1, "HELLO WORLD");
}