#include "hmahl.h"

#define BUFFER_SIZE_1 12
#define BUFFER_SIZE_2 18
#define BUFFER_SIZE_3 36

void print(const char* buffer, const size_t count) {
  for (size_t i = 0; i < count; i++) {
    if (buffer[i] == 0) printf("\\0");
    else putchar(buffer[i]);
  }
}

int main() {
  puts("### Test first file crop\n----");
  {
    char buffer1[BUFFER_SIZE_1];
    bhmah(buffer1, BUFFER_SIZE_1, "file1.txt", "file2.txt");
    print(buffer1, BUFFER_SIZE_1);
  }
  puts("\n----\n");

  puts("### Test second file crop\n----");
  {
    char buffer2[BUFFER_SIZE_2];
    bhmah(buffer2, BUFFER_SIZE_2, "file1.txt", "file2.txt");
    print(buffer2, BUFFER_SIZE_2);
  }
  puts("\n----\n");

  puts("### Test third file full + overflow\n----");
  {
    char buffer3[BUFFER_SIZE_3];
    bhmah(buffer3, BUFFER_SIZE_3, "file1.txt", "file2.txt");
    print(buffer3, BUFFER_SIZE_3);
  }
  puts("\n----\n");
}
