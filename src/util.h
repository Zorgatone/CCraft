#pragma once
#ifndef UTIL_H
#define UTIL_H

#include "die.h"
#include "order32.h"

void nbo_fwrite(const void *buffer, size_t size, size_t count, FILE *stream);
void nbo_fread(void *buffer, size_t size, size_t count, FILE *stream);

#endif
