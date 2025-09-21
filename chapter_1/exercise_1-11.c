// To test the word count program from the book,
// we want to test for four possible bugs:
// 1) Changing state to IN where we shouldn't
// 2) Changing state to OUT where we shouldn't
// 3) Staying in state IN when we should change to OUT
// 4) Staying in state OUT when we should change to IN

// I'll go ahead and accept that a word is any string
// not starting with a space, tab, or newline.
// Likewise, I'll go ahead and accept that a word always
// ends with either a space, tab, or newline.
// (Neither of the above is actually the case)

// With the above assumptions, I would expect that control
// characters like "EOF" would cause trouble, so I would find
// ways to input those and see if they were counted as words.
// I would also test with strings I expect to work,
// like just one word, or two words, or no words.

// There is noticably also a bug in the code from the book
// (I trust it's intentional lol) which sets c to '\t' instead
// of trying to compare it. This is why testing with some normal
// strings is also a good practice.

// This also probably should've just been a text file. Idk why I made it a C file.