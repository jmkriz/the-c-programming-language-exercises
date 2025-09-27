#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    printf("SIGNED CHAR MAX: %d\n", SCHAR_MAX);
    printf("SIGNED CHAR MIN: %d\n", SCHAR_MIN);
    printf("UNSIGNED CHAR MAX: %d\n", UCHAR_MAX);
    printf("UNSIGNED CHAR MIN: %d\n", 0); //Min of unsigned is always zero

    printf("SIGNED SHORT MAX: %d\n", SHRT_MAX); //Shorts are signed by default
    printf("SIGNED SHORT MIN: %d\n", SHRT_MIN);
    printf("UNSIGNED SHORT MAX: %d\n", USHRT_MAX);
    printf("UNSIGNED SHORT MIN: %d\n", 0);

    printf("SIGNED INT MAX: %d\n", INT_MAX); //Ints are also signed by default
    printf("SIGNED INT MIN: %d\n", INT_MIN);
    printf("UNSIGNED INT MAX: %d\n", UINT_MAX);
    printf("UNSIGNED INT MIN: %d\n", 0);

    printf("SIGNED LONG MAX: %d\n", LONG_MAX);
    printf("SIGNED LONG MIN: %d\n", LONG_MIN);
    printf("UNSIGNED LONG MAX: %d\n", ULONG_MAX);
    printf("UNSIGNED LONG MIN: %d\n", 0);

    printf("FLOAT MAX: %f\n", FLT_MAX);
    printf("FLOAT MIN: %f\n", -FLT_MAX); //FLT_MIN is the smallest *positive* float

    printf("DOUBLE MAX: %f\n", DBL_MAX);
    printf("DOUBLE MIN: %f\n", -DBL_MAX);

    printf("LONG DOUBLE MAX: %Lf\n", LDBL_MAX);
    printf("LONG DOUBLE MIN: %Lf\n", -LDBL_MAX);

    //todo: calculate the values above instead of just using the
    //      values from the header files
}