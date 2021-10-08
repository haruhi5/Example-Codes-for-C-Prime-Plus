#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>

int main(int argc, char *argv[])
{
    int i, times;
    printf("Argc: %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("Argv[%d]:%s\n", i, argv[i]);
    if (argc < 2 or (times = atoi(argv[1])) < 1)        // and : if first false then look second
        printf("Usage: %s positive-number\n", argv[0]); // if first true then don't need 2
    else
    {

        printf("times: %d\n", times);
        for (i = 0; i < times; i++)
            puts("Hello, good looking!");
    }
    return 0;
}