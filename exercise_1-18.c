#include <stdio.h>
#define MAXLINE 1000

void delete_char(char s[], int len, int pos) {
    for (int i = pos; i < len; i++) {
        s[i] = s[i + 1];
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
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        for (int i = len; i >= 0 && (line[i] == '\t' || line[i] == ' ' || line[i] == '\n' || line[i] == '\0'); --i) {
            if (line[i] == '\t' || line[i] == ' ') {
                delete_char(line, len, i);
            }
        }
        printf("%s", line);
    }
}