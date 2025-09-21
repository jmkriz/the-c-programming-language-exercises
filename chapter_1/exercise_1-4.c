// Exercise 1-4

#include <stdio.h>

int main() {
    float fahr, celc;
    int lower = 0, upper = 300, step = 20;
    
    celc = lower;
    printf("  C    F\n");
    while (celc <= upper) {
        fahr = celc * 9.0/5.0 + 32.0;
        printf("%3.0f %6.1f\n", celc, fahr);
        celc = celc + step;
    }
}