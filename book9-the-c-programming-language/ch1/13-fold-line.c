#include <ctype.h>
#include <stdio.h>

#define BUFFER_LENGTH 1024
#define COL_LIMIT 20

int getline2(char* buffer, size_t sz);
void fold(char* buf, size_t bufsz, size_t col_len);

int main(int argc, char* argv[]) {
  char buffer[BUFFER_LENGTH];

  while (getline2(buffer, BUFFER_LENGTH) > 0) {
    fold(buffer, BUFFER_LENGTH, COL_LIMIT);
    printf("%s", buffer);
  }

  return 0;
}

/*
 * find_previous_space: finds the nearest space to the left of from_pos.
 */
size_t find_previous_space(char* buf, size_t from_pos) {
  while (from_pos > 0 && !isspace(buf[from_pos])) {
    from_pos--;
  }
  return from_pos;
}

/*
 * fold: breaks a line if exceeds col_len
 */
void fold(char* buf, size_t bufsz, size_t col_len) {
  size_t i = 0;
  int c;
  size_t col_start = i;
  while (i < bufsz && (c = buf[i]) != '\0') {
    if ((i - col_start) >= col_len) {
      // we need to find the previous space if this is a word
      size_t fold_pos = find_previous_space(buf, i);
      if (fold_pos > 0) {
        buf[fold_pos] = '\n';
        col_start = fold_pos;
      } else {
        buf[i] = '\n';
        col_start = i;
      }
    }
    i++;
  }
}

int getline2(char* buf, size_t bufsz) {
  int c;
  int i = 0;
  while ((c = getchar()) != EOF && c != '\n' && i < bufsz - 2) {
    buf[i++] = c;
  }
  if (c == '\n') {
    buf[i++] = c;
  }
  buf[i] = '\0';
  return i;
}
