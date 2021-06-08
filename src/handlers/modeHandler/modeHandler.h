#ifndef CONNECTFOUR_MODEHANDLER_H
#define CONNECTFOUR_MODEHANDLER_H

void two_player_mode();
void one_player_mode();
void computer_vs_computer_mode();
void practice_mode();

void (*MODES[4]) ();

void show_modes();

void init_modes();

int play_mode(int mode);

bool has_won(char color);

bool is_column_full(int index);

/*
 * return codes:
 *      2: if the column is full
 */
int put_color_to_board(int column_index, char color);


#endif //CONNECTFOUR_MODEHANDLER_H
