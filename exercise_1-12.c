#include <stdio.h>

#define IN 1
#define OUT 0

int main() {
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '\t' || c == '\n' || c == ' ') {
            if (state == IN) {
                state = OUT;
                putchar('\n');
            }
        }
        else {
            putchar(c);
            // Google says assignment is faster than comparison,
            // so I might as well assign every time?
            state = IN;
        }
    }
}