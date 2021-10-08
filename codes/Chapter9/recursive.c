#include <stdio.h>

void to_binary(unsigned long n);

int main(void)
{
    unsigned long number;
    printf("Enter a integer (q to quit): ");
    while (scanf("%lu,", &number) == 1)
    { // %lu unsigned long
        printf("%lu Binary equivaluent ", number);
        to_binary(number);
        putchar('\n');
        printf("Enter a integer (q to quit): ");
    }
    printf("Done.\n");
    return 0;
}

void to_binary(unsigned long number)
{
    int mod;
    mod = number % 2; // x = bn * 2^n + bn-1 * 2^(n-1) + ... + b0 * 2^0
    if (number >= 2)  // x/2 = bn * 2^(n-1) + ... + b1 * 2^0 + b0 * 2^(-1) right shift and get mod bit
        to_binary(number / 2);
    putchar(mod == 0 ? '0' : '1');
    return;
}