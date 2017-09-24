#pragma once
#ifndef DIE_H
#define DIE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void vsfdie(FILE *stream, int code, const char *format, va_list arg);
void sfdie(FILE * stream, int code, const char *format, ...);
void sdie(int code, const char *format, ...);
void die(const char *format, ...);

static inline void vsdie(int code, const char *format, va_list arg) {
  vsfdie(stderr, code, format, arg);
}

static inline void vfdie(FILE *stream, const char *format, va_list arg) {
  vsfdie(stream, EXIT_FAILURE, format, arg);
}

static inline void vdie(const char *format, va_list arg) {
  vsdie(EXIT_FAILURE, format, arg);
}

#endif
