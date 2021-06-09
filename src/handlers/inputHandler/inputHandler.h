#ifndef CONNECTFOUR_INPUTHANDLER_H
#define CONNECTFOUR_INPUTHANDLER_H


int get_main_menu_choice();
int get_index_where_to_put();
int get_random_column();

char **get_two_player_name();
char* get_player_name();

struct Player *get_two_players();
struct Player *get_one_player_and_computer();
struct Player *get_two_computers();

void free_players(struct Player *players);
void free_computers(struct Player *players);
void free_human_and_computer(struct Player *players);




#endif //CONNECTFOUR_INPUTHANDLER_H
