#include <stdio.h>
#define MAXLINE 1000
#define TAB_SIZE 8

// Replace tabs with the correct number of spaces
// If this would cause the string to be larger than 1000 characters, just cut off the end
void detab(char s[], int lim, int tab_size) {
    char scratch[lim];
    int i;
    int offset = 0;
    for (i = 0; (s[i] != '\0') && ((i + offset) < (lim - 1)); ++i) {
        if (s[i] == '\t') {
            do {
                scratch[i + offset] = ' ';
                offset++;
            } while (((i + offset) % tab_size != 0) && ((i + offset) < (lim - 1)));
            offset--; //The last offset is not desired
        }
        else {
            scratch[i + offset] = s[i];
        }
    }
    scratch[i + offset] = '\0';
    // I haven't learned the "right" way to do this yet, so I'm doing it the ugly way instead
    for (i = 0; i < lim; i++) {
        s[i] = scratch[i];
    }
}

int get_line(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i) {
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
        detab(line, MAXLINE, TAB_SIZE);
        printf("%s", line);
    }
}