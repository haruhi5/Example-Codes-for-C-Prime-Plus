#include <stdio.h>
#define FUNDLEN 50

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
}; // struct cannot be external !!!

double sum(double, double);        // functions are defaultly set as extern, unless declared static
double sum2(const struct funds *); // detail in Chpater 12.1.11
double sum3(struct funds);

int main(void)
{
    extern struct funds stan;
    printf("Stan has a total of $%.2f.\n", sum(stan.bankfund, stan.savefund));
    printf("Stan has a total of $%.2f.\n", sum2(&stan));
    printf("Stan has a total of $%.2f.\n", sum3(stan));
    return 0;
}
