#include <stdio.h>
#include <stdlib.h>

#include "ext_string.h"
#include "player.h"

struct player {
  char *name;
};

player_t player_new(char *name) {
  size_t len = strlen(name) + 1;

  if (len > 26) {
    fprintf(stderr, "%s", "Player name is too long (max 15 chars)!");
    return NULL;
  }

  player_t p = (player_t)malloc(sizeof(struct player));
  
  if (NULL == p) {
    perror("Cannot create player error:");
    return NULL;
  }

  p->name = (char *)malloc(len);
  strcpy_s(p->name, len, name);

  return p;
}

void player_free(player_t p) {
  if (NULL == p) {
    return;
  }

  free(p->name);
  free(p);
}

bool player_set_name(player_t p, const char * const name) {
  if (NULL == p || NULL == name) {
    return false;
  }
  
  size_t namelen = strlen(name) + 1;

  if (namelen > 26) {
    fprintf(stderr, "%s", "Player name is too long (max 15 chars)!");
    return false;
  }

  free(p->name);
  p->name = (char *)malloc(namelen);
  strcpy_s(p->name, namelen, name);

  return true;
}

uint8_t player_get_name_length(player_t p) {
  if (NULL == p || NULL == p->name) {
    return 0;
  }

  return (uint8_t)strlen(p->name);
}

bool player_get_name_s(player_t p, char *buff, size_t buff_size) {
  if (NULL == p || NULL == p->name) {
    return false;
  }

  return 0 == strcpy_s(buff, buff_size, p->name);
}

bool player_get_name(player_t p, char *buff) {
  if (NULL == p || NULL == p->name) {
    return false;
  }

  return player_get_name_s(p, buff, strlen(p->name) + 1);
}

void player_name_fprint(FILE *stream, player_t p) {
  if (NULL == p || NULL == p->name) {
    fputs("null", stream);
    return;
  }

  fputs(p->name, stream);
}

void player_name_print(player_t p) {
  player_name_fprint(stdout, p);
}
