#include <stdlib.h>
#include "stdio.h"
#include "inputHandler.h"
#include "../../board/board.h"
#include "../outputHandler/outputHandler.h"
#include "../otherHeaders/colors.h"
#include "../otherHeaders/debug.h"
#include "../gameLogicHandler/gameLogicHandler.h"

int get_main_menu_choice(){
    int choice;

    show_enter_your_choice();
    while(scanf("%d" ,&choice) != 1 || !(0 <= choice && choice <= 4))
    {
        printf("Invalid choice!\n");
        show_enter_your_choice();
        while(getchar() != '\n');
    }

    return choice;
}

int get_index_where_to_put(){
    int choice;

    show_enter_your_choice();
    while(scanf("%d" ,&choice) != 1 || !(1 <= choice && choice <= BOARD_SIZE))
    {
        printf("Invalid choice!\n");
        show_enter_your_choice();
        while(getchar() != '\n');
    }

    return choice - 1;
}


char** get_two_player_name(){
    char **player_names = malloc(2 * sizeof(char *));
    player_names[0] = malloc(100 * sizeof(char));
    player_names[1] = malloc(100 * sizeof(char));

    debug_printf("player_names address: %p\n", player_names);
    debug_printf("player_names[0] address: %p\n", player_names[0]);
    debug_printf("player_names[1] address: %p\n", player_names[1]);


    show_enter_player_name(1);
    scanf("%99s", player_names[0]);

    printf("\n");

    show_enter_player_name(2);
    scanf("%99s", player_names[1]);

    clear_console();

    return player_names;
}

char* get_player_name(){
    char *player_name = malloc(100 * sizeof(char));

    debug_printf("player_name address: %p\n", player_name);

    show_enter_player_name(1);
    scanf("%99s", player_name);

    clear_console();
    
    return player_name;
}

int get_number_of_victories(){
    int choice;

    printf("Number of victories to end the game (max 100)\n");
    printf("> ");
    while(scanf("%d" ,&choice) != 1 || !(1 <= choice && choice <= 100)){
        printf("Invalid choice!\n");
        printf("> ");
        while(getchar() != '\n');
    }
    return choice;
}

struct Player *get_two_players() {
    char **player_names = get_two_player_name();
    struct Player player1;
    struct Player player2;

    player1.name = player_names[0];
    player2.name = player_names[1];

    free(player_names);

    player1.is_human = true;
    player2.is_human = true;

    player1.token = 'X';
    player2.token = 'O';

    player1.color = BLUE;
    player2.color = RED;

    struct Player *players = malloc(2 * sizeof(struct Player));

    debug_printf("players address: %p\n", players);

    players[0] = player1;
    players[1] = player2;

    return players;
}

struct Player *get_one_player_and_computer(){
    struct Player player1;
    struct Player player2;

    player1.name = get_player_name();
    player2.name = "Computer";

    player1.token = 'X';
    player2.token = 'O';

    player1.is_human = true;
    player2.is_human = false;

    player1.color = BLUE;
    player2.color = RED;

    struct Player *players = malloc(2 * sizeof(struct Player));

    players[0] = player1;
    players[1] = player2;

    return players;
}

struct Player *get_two_computers() {
    struct Player player1;
    struct Player player2;

    player1.name = "Computer_Bobby";
    player2.name = "Computer_Alice";

    player1.token = 'X';
    player2.token = 'O';

    player1.is_human = false;
    player2.is_human = false;

    player1.color = BLUE;
    player2.color = RED;

    struct Player *players = malloc(2 * sizeof(struct Player));

    players[0] = player1;
    players[1] = player2;

    return players;
}


void free_players(struct Player *players){
    free(players[0].name);
    free(players[1].name);

    free(players);
}

void free_human_and_computer(struct Player *players){
    free(players[0].name);

    free(players);
}

void free_computers(struct Player *players) {

    free(players);
}
