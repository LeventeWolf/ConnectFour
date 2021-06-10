#include <stdbool.h>

#ifndef CONNECTFOUR_MODEHANDLER_H
#define CONNECTFOUR_MODEHANDLER_H

void two_player_mode();
void one_player_mode();
void computer_vs_computer_mode();
void practice_mode();

void (*MODES[4]) ();

void init_modes();

struct Player {
    char* name;
    char* color;
    char token;
    bool is_human;

    //computer_only
    int* columns_to_avoid;
};

int play_mode(int mode);


#endif //CONNECTFOUR_MODEHANDLER_H
