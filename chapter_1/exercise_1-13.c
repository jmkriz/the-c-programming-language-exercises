#include <stdio.h>
#define LONGEST_WORD 46
#define HISTOGRAM_LENGTH 10

// General thoughts: I'm nesting a lot, and I don't really like that. Can I refactor to nest less?

int main() {
    int c;
    int word_count = 0, word_length = 0;
    int word_lengths[LONGEST_WORD] = {0}; //This way of initializing arrays isn't introduced yet, but I can't be bothered to write a for loop for this like the book does

    // get word lengths
    do {
        // do while is also not introduced yet
        // By book convention, only whitespace characters are counted as word ends
        c = getchar();
        if (c == '\n' || c == '\t' || c == ' ' || c == EOF) {
            if (word_length) {
                word_count += 1;
                word_lengths[word_length] += 1;
                word_length = 0;
            }
        }
        else {
            word_length += 1;
        }
    } while (c != EOF);

    //print histogram
    printf("Proportions of word lengths out of %d words\n", word_count);
    for (int i = 0; i < LONGEST_WORD; i++) {
        if (word_lengths[i]) {
            float proportion = (float)word_lengths[i] / word_count;
            printf("%2d|", i);
            for (int j = 0; j < HISTOGRAM_LENGTH; j++) {
                if (proportion * HISTOGRAM_LENGTH >= j) {
                    printf("#");
                }
                else {
                    printf(" ");
                }
            }
            printf(" (%d words)\n", word_lengths[i]);
        }
    }
}