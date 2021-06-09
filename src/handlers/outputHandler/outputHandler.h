#ifndef CONNECTFOUR_OUTPUTHANDLER_H
#define CONNECTFOUR_OUTPUTHANDLER_H

void show_mode_title(char *mode);

void show_modes();

void show_victory(struct Player player);
void show_draw();

void show_player_turn(struct Player player);

void show_enter_player_name(int player_number);

void show_enter_your_choice();


void clear_console();

#endif //CONNECTFOUR_OUTPUTHANDLER_H
