#include <stdio.h>
#define MAXLINE 1000
#define YES     1
#define NO      0

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
    char stack[MAXLINE];
    int stack_index = 0;
    int mismatch_line[MAXLINE];
    char mismatch_char[MAXLINE];
    int mismatch_index = 0;
    int line_count = 0;
    int len;

    int in_comment  = NO;
    int in_string = NO;
    int in_char = NO;

    // god this is ugly
    while ((len = get_line(line, MAXLINE)) > 0) {
        in_comment = remove_comments(line, MAXLINE, in_comment);
        line_count++;
        for (int i = 0; i < len; i++) {
            if (!in_comment && !in_string && !in_char) {
                if (line[i] == '"') {
                    in_string = YES;
                } else if (line[i] == '\'') {
                    in_char = YES;
                } else if (line[i] == '[' || line[i] == '{' || line[i] =='(') { //assuming these all can nest indefinitely
                    stack_index++;
                    stack[stack_index] = line[i];
                } else if (line[i] == ']') {
                    if (stack[stack_index] == '[') {
                        stack_index--;
                    } else {
                        mismatch_line[mismatch_index] = line_count;
                        mismatch_char[mismatch_index] = line[i];
                        mismatch_index++;
                    }
                } else if (line[i] == '}') {
                    if (stack[stack_index] == '{') {
                        stack_index--;
                    } else {
                        mismatch_line[mismatch_index] = line_count;
                        mismatch_char[mismatch_index] = line[i];
                        mismatch_index++;
                    }
                } else if (line[i] == ')') {
                    if (stack[stack_index] == '(') {
                        stack_index--;
                    } else {
                        mismatch_line[mismatch_index] = line_count;
                        mismatch_char[mismatch_index] = line[i];
                        mismatch_index++;
                    }
                }
            } else if (in_string && line[i] == '"') {
                in_string = NO;
            } else if (in_char && line[i] == '\'') {
                in_char = NO;
            }
        }
        in_string = NO;
        in_char = NO;
    }

    if (!mismatch_index && !stack_index) {
        printf("No errors!\n");
    } else {
        if (mismatch_index) {
            for (int i = 0; i < mismatch_index; i++) {
                printf("Error on line %d: mismatched %c\n", mismatch_line[i], mismatch_char[i]);
            }
        }
        if (stack_index) {
            for (int i = stack_index; i > 0; i--) {
                printf("Error: Unclosed %c\n", stack[i]);
            }
        }
    }
}