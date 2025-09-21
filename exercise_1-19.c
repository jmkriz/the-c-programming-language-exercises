#include <stdio.h>
#define MAXLINE 1000

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

// Written assuming all lines end in \n\0
// Static variables and returning pointers is outside the scope of chapter 1,
// was I expected to reverse the string in-place?
// From what I'm reading static might *not* be a good way to do this,
// even though it does technically work for this problem.
char* reverse_line(char s[], int len) {
    static char rev[MAXLINE];
    int j = 0; //this feels ugly
    for (int i = len - 2; i >= 0; i--) {
        rev[j] = s[i];
        j++;
    }
    rev[j] = '\n';
    rev[j+1] = '\0';
    return rev;
}

int main() {
    int len;
    char line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        printf("%s", reverse_line(line, len));
    }
}