#include <stdio.h>
#include <time.h>

extern unsigned int rand0(void);
extern void set_seed(unsigned int seed);

int main(void)
{
    int count;

    for (count = 0; count < 5; count++)
    {
        printf("%d\n", rand0());
    }

    printf("Initinal the seed using time\n");
    set_seed((unsigned int)time(0));
    for (count = 0; count < 5; count++)
    {
        printf("%d\n", rand0());
    }

    unsigned seed;
    printf("Please enter your choice of seed: ");
    while (scanf("%u", &seed) == 1)
    {
        set_seed(seed);
        for (count = 0; count < 5; count++)
        {
            printf("%d\n", rand0());
        }
    }
    printf("Done");

    return 0;
}