#ifndef __LIB_HMAHL_H__
#define __LIB_HMAHL_H__

#include <stddef.h>
#include <stdio.h>

void bhmah_impl(char* buffer, size_t bufferSize, const char* path1, ...);
void fhmah_impl(FILE* stream, const char* path1, ...);

#define bhmah(buffer, bufferSize, ...) bhmah_impl(buffer, bufferSize, __VA_ARGS__, NULL);
#define fhmah(stream, ...) fhmah_impl(stream, __VA_ARGS__, NULL);
#define hmah(...) fhmah(stdout, __VA_ARGS__)

#endif // __LIB_HMAHL_H__