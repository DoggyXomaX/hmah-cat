#include "hmahl.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK_SIZE 1024

#if HMAH_DEBUG
  #define err(...) fprintf(stderr, __VA_ARGS__)
#else
  #define err(...)
#endif

size_t hmah_loadfile(const char* path, FILE** file) {
  *file = fopen(path, "r");
  if (*file == NULL) {
    err("Failed to open file %s!\n", path);
    *file = NULL;
    return 0;
  }

  const int seekResult = fseek(*file, 0, SEEK_END);
  if (seekResult != 0) {
    err("Failed to seek file %s!\n", path);
    fclose(*file);
    return 0;
  }

  const long fileSize = ftell(*file);
  if (fileSize == -1L || fileSize == 0) {
    err("Failed to get file %s size!\n", path);
    fclose(*file);
    return 0;
  }

  fseek(*file, 0, SEEK_SET);

  return fileSize;
}

void bhmah_impl(char* buffer, const size_t bufferSize, const char* path1, ...) {
  if (buffer == NULL || bufferSize == 0) return;

  char* ptr = buffer;
  const char* endPtr = buffer + bufferSize - 1;

  const char* path = path1;

  va_list args;
  va_start(args, path1);

  do {
    if (path == NULL) break;

    FILE* file;
    const size_t fileSize = hmah_loadfile(path, &file);

    path = va_arg(args, const char*);

    if (fileSize == 0) continue;

    if (ptr + fileSize > endPtr) {
      fread(ptr, 1, endPtr - ptr + 1, file);
      fclose(file);
      break;
    }

    fread(ptr, 1, fileSize, file);
    ptr += fileSize;

#if HMAH_ENDL
    if (ptr + 1 <= endPtr) {
      *ptr = '\n';
      ptr++;
    }
#endif
  } while(1);

  va_end(args);
}

void fhmah_impl(FILE* stream, const char* path1, ...) {
  if (stream == NULL) return;

  const char* path = path1;

  va_list args;
  va_start(args, path1);

  do {
    if (path == NULL) break;

    FILE* file;
    const size_t fileSize = hmah_loadfile(path, &file);

    path = va_arg(args, const char*);

    if (fileSize == 0) continue;

    do {
      char rBuffer[CHUNK_SIZE];

      const size_t bytes = fread(rBuffer, 1, CHUNK_SIZE, file);
      if (bytes == 0) {
#if HMAH_ENDL
        fputc('\n', stream);
#endif
        break;
      }

      fwrite(rBuffer, 1, bytes, stream);
    } while(1);
  } while(1);

  va_end(args);
}
