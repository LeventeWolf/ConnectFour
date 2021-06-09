#include <stdbool.h>
#include "../../board/board.h"

#ifndef CONNECTFOUR_GAMELOGICHANDLER_H
#define CONNECTFOUR_GAMELOGICHANDLER_H

bool is_cell_empty(int i, int j);

bool is_column_full(int index);

bool has_won(char color);

/*
 * return codes:
 *      2: if the column is full
 */
int put_color_to_board(int column_index, char color);


#endif //CONNECTFOUR_GAMELOGICHANDLER_H
