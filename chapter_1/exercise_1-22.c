// This program seems to occasionally fold a line one character early.
// I think it has to do with whether or not the previous line ended in a space or not.
// It might instead have to do with the line starting with a space. I'm not sure.

#include <stdio.h>
#define MAXLINE 1000
#define TAB_SIZE 8
#define LINE_SIZE 80

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

// Like detab, if we go  over 1000 characters, cut off the end
void fold(char s[], int lim, int tab_size, int line_size) {
    char scratch[lim];
    scratch[0] = s[0];
    int i, j;
    for (i = j = 1; (i < lim - 1) && (j < lim - 1) && (s[i] !=  '\0'); i++, j++) {
        if (i % line_size == 0) {
            // put a \n at the end of a line break, removing extra whitespace
            do {
                j--;
            } while(scratch[j] == ' ' || scratch[j] == '\t');
            j++;
            scratch[j]  = '\n';

            // go past the extra whitespace after the line break
            while(s[i] == ' ' || s[i] == '\t') {
                i++;
            }
            j++;
        }
        // handle the edge case of the last line being only blanks
        if (s[i] == '\0') {
            break;
        }
        scratch[j] = s[i];
    }
    scratch[j] = '\0';

    for (int i = 0; i < lim; i++) {
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
        fold(line, MAXLINE, TAB_SIZE, LINE_SIZE);
        printf("%s", line);
    }
}