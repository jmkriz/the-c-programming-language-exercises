#include <stdio.h>

int main() {
    int c;
    int lastc;
    while ((c = getchar()) != EOF) {
        if (lastc == '\n' || lastc == '\t' || lastc == ' ') {
            if (c != '\n' && c != '\t' && c != ' ') {
                putchar(c);
            }
        }
        else {
            putchar(c);
        }
        lastc = c;
    }
}