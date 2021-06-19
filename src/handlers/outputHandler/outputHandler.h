#ifndef CONNECTFOUR_OUTPUTHANDLER_H
#define CONNECTFOUR_OUTPUTHANDLER_H

void show_game_title();
void show_mode_title(char *mode);
void show_modes();

void show_victory(struct Player player);
void show_draw();

void show_player_turn(struct Player player);

void show_enter_player_name(int player_number);
void show_enter_your_choice();

void show_new_line();
void show_players_names_and_victories();
void show_playing_until_n_victories(int number_of_victories);
void show_next_round();
void show_congratulations();
void show_practice_winner_player(struct Player player);

void clear_console();

#endif //CONNECTFOUR_OUTPUTHANDLER_H
