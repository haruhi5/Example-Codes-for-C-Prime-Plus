#include <stdio.h>
#define FUNDLEN 50
// multiple files one main allowed

struct funds
{
    char bank[FUNDLEN];
    double bankfund;
    char save[FUNDLEN];
    double savefund;
};

double sum(double, double);
double sum2(const struct funds *);
double sum3(struct funds);

struct funds stan = {
    "Garlic-Melon Bank",
    4032.27,
    "Lucky's Saving and Loan",
    8543.94};

double sum(double x, double y)
{
    return x + y;
}

double sum2(const struct funds *x)
{
    return x->bankfund + x->savefund;
}

double sum3(struct funds x){
    return x.bankfund+x.savefund;
}