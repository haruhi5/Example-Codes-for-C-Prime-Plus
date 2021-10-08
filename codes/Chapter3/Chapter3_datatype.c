#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
int main()
{
    __INT_FAST32_TYPE__ me32;
    me32 = 45933945;
    printf("me32 = %" PRId32 "\n", me32);
    getchar();
    return 0;
}