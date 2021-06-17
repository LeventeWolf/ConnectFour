#include "../handlers/modeHandler/modeHandler.h"

#ifndef CONNECTFOUR_BOARD_H
#define CONNECTFOUR_BOARD_H

//       -- Board --
//
//      0 1 2 3 4 5 6 7
//   0 | | | | | | | | |
//   1 | | | | | | | | |
//   2 | | | | | | | | |
//   3 | | | | | | | | |
//   4 | | | | | | | | |
//   5 | | | | | | | | |
//   6 | | | | | | | | |
//   7 | | | | | | | | |
//     ─────────────────
//     /1 2 3 4 5 6 7 8\

#define TOKEN "⬤"
#define BOARD_SIZE 8

extern char** board;

void init_board();

void free_board();

void show_board(struct Player *players);


#endif //CONNECTFOUR_BOARD_H
