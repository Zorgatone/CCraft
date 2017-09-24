#include <stdarg.h>

#include "die.h"

void vsfdie(FILE * stream, int code, const char *format, va_list arg) {
  vfprintf(stream, format, arg);
  va_end(arg);
  exit(code);
}

void sfdie(FILE * stream, int code, const char *format, ...) {
  va_list args;
  va_start(args, format);
  vsfdie(stream, code, format, args);
}

void sdie(int code, const char *format, ...) {
  va_list args;
  va_start(args, format);
  vsfdie(stderr, code, format, args);
}

void fdie(FILE *stream, const char *format, ...) {
  va_list args;
  va_start(args, format);
  vfdie(stream, format, args);
}

void die(const char *format, ...) {
  va_list args;
  va_start(args, format);
  vdie(format, args);
}
