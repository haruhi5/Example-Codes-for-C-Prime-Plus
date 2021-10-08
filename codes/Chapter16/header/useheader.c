#include <string.h>
#include <stdio.h>
#include "name_st.h"

int main(void)
{
    names candidate;
    get_names(&candidate);
    printf("Welcome ");
    show_names(&candidate);
    printf(" to this program!\n");

    printf("The file is %s.\n", __FILE__);
    printf("The date is %s.\n", __DATE__);
    printf("The time is %s.\n", __TIME__);
    printf("The version is %ld.\n", __STDC_VERSION__);
    printf("This is line %d.\n", __LINE__);
    printf("This function is %s\n", __func__);
    getchar();
    return 0;
}