#include <stdio.h>
void report_count();
void accumaulate(int k); // functions are defaultly set as extern, unless declared static
                         // detail in Chpater 12.1.11
int count = 0;           // external link

int main(void)
{
    int value;
    register int i;

    printf("Enter a positive integer (0 to quit): ");
    while (scanf("%d", &value) == 1 && value > 0)
    {
        ++count;
        for (i = value; i >= 0; i--)
        {
            accumaulate(i);
        }
        printf("Enter a positive integer (0 to quit): ");
    }
    report_count();
    return 0;
}

void report_count()
{
    printf("Loop executed %d times\n", count);
}