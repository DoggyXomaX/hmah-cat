#include "hmah.h"

void print_usage() {
  printf(
    "Usage: hmah [OPTION]... [FILE]...\n"
    "Concatenate FILE(s) to standard output.\n"
  );
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    print_usage();
    return 0;
  }

  for (int i = 1; i < argc; i++) hmah(argv[i]);
}
