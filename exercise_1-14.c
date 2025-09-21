#include <stdio.h>
#define CHAR_POSS 256
#define HISTOGRAM_LENGTH 30

int main() {
    int c;
    long char_count = 0;
    long char_freq[CHAR_POSS] = {0};
    while ((c = getchar()) != EOF) {
        char_freq[c] += 1;
        char_count += 1;
    }

    //print histogram
    printf("Proportion of each character out of %d characters\n", char_count);
    for (int i = 0; i < CHAR_POSS; i++) {
        if (char_freq[i]) {
            float proportion = (float)char_freq[i] / char_count;
            // I wanted to print the characters instead of just their int counterparts,
            // but handling the newlines and tabs quickly turned into software gore.
            printf("%3d|", i);
            for (int j = 0; j < HISTOGRAM_LENGTH; j++) {
                if (proportion * HISTOGRAM_LENGTH >= j) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
            printf(" (%d occurences)\n", char_freq[i]);
        }
    }
}