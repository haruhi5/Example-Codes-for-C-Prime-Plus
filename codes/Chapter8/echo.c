/*usage:
gcc .\echo.exe < test.txt // from
               > test2.txt // into*/
#include <stdio.h>

int main(void)
{
    char ch;
    // while ((ch = getchar()) != '#')
    while ((ch = getchar()) != EOF)
        putchar(ch);
    return 0;
}