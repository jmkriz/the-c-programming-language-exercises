#include <stdio.h>
#define MAXLINE 1000

int get_line(char s[], int lim) {
    int c, i;
    // the goal of this exercise is to rewrite the loop without using &&
    // that is why this abomination exists
    for (i = 0; (i < lim - 1) == ((c = getchar()) != '\n') == (c != EOF) == 1; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    char line[MAXLINE];
    int len;
    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%s", line);
    }
}