#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include <stdint.h>

typedef struct player *player_t;

// Create new Player object
player_t player_new(char *name);

// Free Player object's memory
void player_free(player_t p);

// Sets name of Player object
bool player_set_name(player_t p, const char * const name);
uint8_t player_get_name_length(player_t p);
bool player_get_name_s(player_t p, char *buff, size_t buff_size);
bool player_get_name(player_t p, char *buff);
void player_name_fprint(FILE *stream, player_t p);
void player_name_print(player_t p);

#endif
