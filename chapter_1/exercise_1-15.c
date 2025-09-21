#include <stdio.h>

float fahr_to_celc(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}

int main() {
    for (int fahr = 0; fahr < 300; fahr += 20) {
        printf("%3d %6.1f\n",  fahr, fahr_to_celc(fahr));
    }
}