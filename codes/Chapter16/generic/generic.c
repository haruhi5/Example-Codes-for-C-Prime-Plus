#include <stdio.h>
#include <math.h>
#include <tgmath.h>

// #pragma c9x on // compiler command
// # if ( (180/(4*atntl(1)))-(180/pi)<1e-6 )
// # endif
#define RAD_TO_DEG (180 / (4 * atanl(1.0)))
#define RAD_TO_DEG2 (180 / M_PI)
#define EQU_RAD_TO_DEG RAD_TO_DEG2 == RAD_TO_DEG ? RAD_TO_DEG2 : RAD_TO_DEG

#define MYTYPE(x) _Generic(x,          \
                           int         \
                           : "int",    \
                             float     \
                           : "float",  \
                             double    \
                           : "double", \
                             default   \
                           : "other")

#define SQRT(x) _Generic((x),          \
                         float         \
                         : sqrtf,      \
                           long double \
                         : sqrtl,      \
                           default     \
                         : sqrtf)(x) // careful: (x)
#define SIN(x) _Generic((x),          \
                        float         \
                        : sinf,       \
                          long double \
                        : sinl,       \
                          default     \
                        : sin)(x / RAD_TO_DEG2)

int main(void)
{
    printf("Equal: %d\n", RAD_TO_DEG2 == RAD_TO_DEG);
    printf("RAD_TO_DEG: %lf\n", RAD_TO_DEG);
    printf("RAD_TO_DEG2: %f\n", RAD_TO_DEG2);
    printf("RAD_TO_DEG: %.17lf\n", atanf(1)); // in my computer, atanl(1) outcome is 0
                                              // maybe overflow
                                              //  warning: format '%lf' expects argument of type 'double',
                                              // but argument 2 has type 'long double' [-Wformat=]
                                              //  https://stackoverflow.com/questions/4089174/printf-and-long-double
    int d = 5;
    printf("%s\n", MYTYPE(d));
    printf("%s\n", MYTYPE(d * 2.0));

    float x = 45.0f;
    double xx = 45.0;
    long double xxx = 45.0L;

    printf("%.17lf\n", SQRT(x));
    printf("%.17lf\n", SQRT(xx));
    printf("%.17lf\n", SQRT(xxx));
    printf("%.17f\n", SQRT(xxx));

    return 0;
}