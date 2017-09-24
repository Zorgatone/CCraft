#pragma once
#ifndef VERSION_H
#define VERSION_H

#include <stdint.h>
#include "order32.h"

#if ENDIAN_ORDER==LITTLE_ENDIAN
  typedef union version {
    uint32_t number;
    struct {
      const uint8_t build;
      const uint8_t patch;
      const uint8_t minor;
      const uint8_t major;
  };
  } version_t;
#elif ENDIAN_ORDER==BIG_ENDIAN
  typedef const union version {
    uint32_t number;
    struct {
      const uint8_t major;
      const uint8_t minor;
      const uint8_t patch;
      const uint8_t build;
    };
  } version_t;
#else
  #error "Unsupported Hardware!"
#endif

extern const version_t version;
extern const uint32_t UUID;

#endif
