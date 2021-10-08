#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double *ptd;
    int max;
    int number;
    int i = 0;

    puts("What is the maximum number of type double enteries?");
    if (scanf("%d", &max) != 1)
    {
        puts("Number not correctly entered -- end!\n");
        exit(EXIT_FAILURE);
    }
    ptd = (double *)malloc(max * sizeof(double));
    if (ptd == NULL)
    {
        puts("Memory allocation failed -- end!\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter the values:\n");
    while (i < max && scanf("%lf", &ptd[i]) != 0)
        ++i;
    printf("Here are your %d enteries:\n", number = i);
    for (i = 0; i < number; i++)
    {
        printf("%7.2f", ptd[i]);
        printf("%7.2f\n", *(ptd + i));
        if (i % 7 == 6)
            putchar('\n');
    }
    if (i % 7 != 0)
        putchar('\n');
    puts("Done.");
    free(ptd);
    return 0;
}