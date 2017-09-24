#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "version.h"
#include "save_manager.h"
#include "util.h"

int main(int argc, char *argv[]) {
  printf(
    "CCraft v%hu.%hu.%hu (build %hu).\n",
    version.major, version.minor, version.patch, version.build
  );

  player_t p = player_new("Zorgatone");

  //save_write(p);
  save_load(&p);
  printf("%s", "Your player name is: ");
  player_name_print(p);
  putchar('\n');

  player_free(p);
  puts("End!");

  return EXIT_SUCCESS;
}
