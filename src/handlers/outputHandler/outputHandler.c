#include <stdio.h>
#include "../../gameMaster/gameMaster.h"

void show_mode_title(char *mode) {
    printf("\n" PADDING "--%s--" PADDING "\n", mode);
}

void show_modes() {
    printf(PADDING "--Main Menu--" PADDING "\n");
    printf("1. Two player     (Player vs Player)\n");
    printf("2. One player     (Player vs Computer)\n");
    printf("3. Computer Fight (Computer vs Computer)\n");
    printf("4. Practice       (Player vs Player N games)\n");
    printf("0. Exit\n");
}

void show_victory(char *name) {
    printf("\n" PADDING "----%s has just won the game!---\n", name);
    printf(PADDING "      --Congratulations!--\n\n");
}

void show_draw() {
    printf(PADDING "----GAME OVER----\n");
    printf(PADDING "    --DRAW--\n\n");
}