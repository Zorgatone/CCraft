#pragma once
#ifndef SAVE_MANAGER_H
#define SAVE_MANAGER_H

#include "player.h"

#define SAVE_FILE "save.dat"

void save_load(player_t *p);
void save_write(player_t p);

#endif
