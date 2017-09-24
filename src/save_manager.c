#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "save_manager.h"
#include "util.h"
#include "version.h"

void save_load(player_t *p) {
  if (NULL == p) {
    die("Null Player pointer!\n");
  }

  FILE *fp;

  fopen_s(&fp, SAVE_FILE, "rb");

  if (NULL == fp) {
    die("Cannot open save file!\n");
  }

  uint32_t save_uuid;
  nbo_fread(&save_uuid, sizeof(save_uuid), 1, fp);

  if (UUID != save_uuid) {
    die("Not a CCraft save file!\n");
  }

  uint32_t save_version;
  nbo_fread(&save_version, sizeof(save_version), 1, fp);

  if (version.number < save_version) {
    die("Cannot load newer version save file!\n");
  }

  uint8_t pname_len;
  nbo_fread(&pname_len, sizeof(pname_len), 1, fp);

  char *pname_buff = (char *)malloc(pname_len + 1);

  if (NULL == pname_buff) {
    perror("Cannot allocate player buffer with error:");
    exit(EXIT_FAILURE);
  }

  nbo_fread(pname_buff, 1, pname_len, fp);
  pname_buff[pname_len] = '\0';

  player_free(*p);
  *p = player_new(pname_buff);
  free(pname_buff);

  fclose(fp);
}

void save_write(player_t p) {
  if (NULL == p) {
    die("Null Player pointer!\n");
  }

  FILE *fp;

  fopen_s(&fp, SAVE_FILE, "wb");

  if (NULL == fp) {
    die("Cannot open save file!\n");
  }

  uint8_t pname_len = player_get_name_length(p) + 1;
  char *pname_buff = (char *)malloc(pname_len);

  if (NULL == pname_buff) {
    perror("Cannot allocate player name buffer with error:");
    exit(EXIT_FAILURE);
  }

  player_get_name_s(p, pname_buff, pname_len);

  //uint32_t i = 1;
  //fwrite(&i, sizeof(i), 1, fp);

  nbo_fwrite(&UUID, sizeof(UUID), 1, fp);
  nbo_fwrite(&version.number, sizeof(version.number), 1, fp);

  pname_len--;
  nbo_fwrite(&pname_len, sizeof(pname_len), 1, fp);
  fwrite(pname_buff, 1, pname_len, fp);

  free(pname_buff);
  fclose(fp);
}
