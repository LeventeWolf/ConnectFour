#include <stdbool.h>
#include "../../board/board.h"

#ifndef CONNECTFOUR_GAMELOGICHANDLER_H
#define CONNECTFOUR_GAMELOGICHANDLER_H

void play_turn(struct Player player);

void play_human_turn(struct Player player);
void play_computer_turn(struct Player player);

bool is_cell_empty(int i, int j);

bool is_column_full(int index);

bool has_won(char color);

bool can_place_token_here(int i, int j);

int get_array_size(const int *array);

bool contains(const int *array, int column);

int *create_my_array(int size, int default_value);

int number_of_not_full_columns();

/*
 * return codes:
 *      2: if the column is full
 */
int put_color_to_board(int column_index, char color);


#endif //CONNECTFOUR_GAMELOGICHANDLER_H
