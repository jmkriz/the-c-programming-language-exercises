// Remove  all comments from a C program

/* Not just the single line ones,
but also the multi-line ones*/

#include <stdio.h>

#define MAXLINE 1000

// booleans have not been introduced in the book yet
#define NO 0
#define YES 1

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

int remove_comments(char line[], int lim, int in_comment) {
    char scratch[lim];
    int i, j;
    int in_string = NO;
    int in_char = NO;
    for (i = j = 0; i < lim && line[i] != '\0'; i++) {
        if (in_comment) {
            if (line[i] == '*' && line[i+1] == '/') {
                in_comment = NO;
                i++;
            }
        } else if (in_string) {
            scratch[j] = line[i];
            j++;
            if (line[i] == '"') {
                in_string = NO;
            }
        } else if (in_char) {
            scratch[j] = line[i];
            j++;
            if (line[i] == '\'') {
                in_char = NO;
            }
        } else {
            if (line[i] == '/') {
                if (line[i+1] == '/') {
                    scratch[j] = '\n';
                    j++;
                    break;
                }
                if (line[i+1] ==  '*') {
                    in_comment = YES;
                    i++;
                }
            } else if (line[i] == '"') {
                in_string = YES;
            } else if (line[i] == '\'') {
                in_char = YES;
            }
            if (!in_comment) {
                scratch[j] = line[i];
                j++;
            }
        }
    }
    scratch[j] = '\0';
    for (i = 0; i < lim; i++){
        line[i] = scratch[i];
    }
    return in_comment;
}

int main() {
    char line[MAXLINE];
    int len;
    int in_comment = NO;
    while ((len = get_line(line, MAXLINE)) > 0) {
        in_comment = remove_comments(line, MAXLINE, in_comment);
        printf("%s", line);
    }
}