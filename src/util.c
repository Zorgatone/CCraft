#include "util.h"

void nbo_fwrite(const void *buffer, size_t size, size_t count, FILE *stream) {
  #if ENDIAN_ORDER==LITTLE_ENDIAN
    for (size_t n = 0; n < count; n++) {
      for (size_t i = size - 1; i >= 0; i--) {
        fwrite((char *)buffer + (n * size) + i, 1, 1, stream);
        if (i == 0) {
          break;
        }
      }
    }
  #elif ENDIAN_ORDER==BIG_ENDIAN
    fwrite(buffer, size, count, stream);
  #else
    #error "Unsupported Hardware!"
  #endif
}

void nbo_fread(void *buffer, size_t size, size_t count, FILE *stream) {
  #if ENDIAN_ORDER==LITTLE_ENDIAN
    for (size_t n = 0; n < count; n++) {
      for (size_t i = size - 1; i >= 0; i--) {
        fread((char *)buffer + (n * size) + i, 1, 1, stream);
        if (i == 0) {
          break;
        }
      }
    }
  #elif ENDIAN_ORDER==BIG_ENDIAN
    fread(buffer, size, count, stream);
  #else
  #error "Unsupported Hardware!"
  #endif
}
