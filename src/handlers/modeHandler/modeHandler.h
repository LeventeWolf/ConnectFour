#include <stdbool.h>

#ifndef CONNECTFOUR_MODEHANDLER_H
#define CONNECTFOUR_MODEHANDLER_H

void two_player_mode();
void one_player_mode();
void computer_vs_computer_mode();
void practice_mode();

struct Player {
    char* name;
    char* color;
    char token;
    bool is_human;
};

int get_random_column();


void play_human_turn(struct Player player);

void play_computer_turn(struct Player player);

struct Player *get_two_players();

struct Player *get_one_player_and_computer();

struct Player *get_two_computers();

void free_players(struct Player *players);

void free_computers(struct Player *players);

void free_human_and_computer(struct Player *players);


void (*MODES[4]) ();

void init_modes();

int play_mode(int mode);

void play_turn(struct Player player);

bool has_won(char color);

bool is_column_full(int index);

/*
 * return codes:
 *      2: if the column is full
 */
int put_color_to_board(int column_index, char color);

#endif //CONNECTFOUR_MODEHANDLER_H
