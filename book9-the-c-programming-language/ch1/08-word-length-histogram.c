#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 16 /* maximum length of a word for the histogram */
#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */

int main(int argc, char *argv) {
  int c;
  int word_lengths[MAX_LENGTH];
  memset(word_lengths, 0, sizeof(int) * MAX_LENGTH);

  int wordlen = 0;
  int state = OUT;
  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      if (state == IN && wordlen > 0 && wordlen <= MAX_LENGTH) {
        ++word_lengths[wordlen - 1];
      }
      state = OUT;
      wordlen && (wordlen = 0);
    } else if (state == OUT) {
      state = IN;
      wordlen = 0;
    } else {
      ++wordlen;
    }
  }

  for (int i = 0; i < MAX_LENGTH; i++) {
    printf("[%d] = %d\n", i+1, word_lengths[i]);
  }

  return 0;
}
