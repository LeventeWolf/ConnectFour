#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include "modeHandler.h"
#include "../inputHandler/inputHandler.h"
#include "../outputHandler/outputHandler.h"
#include "../../board/board.h"
#include "colors.h"
#include "../gameLogicHandler/gameLogicHandler.h"


#ifndef DEBUGG
#define DEBUG 1
#define debug_print(args ...) if (DEBUG){ printf(RED); printf(args); printf(RESET); }
#endif

void init_modes() {
    MODES[0] = two_player_mode;
    MODES[1] = one_player_mode;
    MODES[2] = computer_vs_computer_mode;
    MODES[3] = practice_mode;
}

int play_mode(int mode) {
    if (mode == 0) return 0;

    clear_console();

    (*MODES[mode - 1])();


    return 1;
}

void play_turn(struct Player player) {
    show_player_turn(player);

    if (player.is_human) {
        play_human_turn(player);
    } else {
        play_computer_turn(player);
        sleep(1);
    }

    clear_console();
}

void play_computer_turn(struct Player player) {
    int error_code;
    int random_column;

    do {
        random_column = get_random_column();
        error_code = put_color_to_board(random_column, player.token);
    } while (error_code != 1);

//    printf("> %d\n", random_column + 1);

}

int get_random_column() {
    return rand() % BOARD_SIZE;
}

void play_human_turn(struct Player player) {
    int error_code;

    do {
        error_code = put_color_to_board(get_index_where_to_put(), player.token);

        if (error_code == 2) printf("The selected column is full!\n");

    } while (error_code != 1);
}

void two_player_mode() {
    show_mode_title("Two Player Mode");

    struct Player *players = get_two_players();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board(players);

        play_turn(player);

        if (has_won(player.token)){
            show_board(players);
            show_victory(player);
            free_players(players);
            return;
        }
    }

    show_draw();
    free_players(players);
}

void one_player_mode() {
    show_mode_title("One Player Mode");

    struct Player *players = get_one_player_and_computer();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board(players);

        play_turn(player);

        if (has_won(player.token)){
            show_board(players);
            show_victory(player);
            free_human_and_computer(players);
            return;
        }
    }

    show_draw();
    free_human_and_computer(players);
}

void computer_vs_computer_mode() {
    show_mode_title("Computer Vs Computer Mode");

    struct Player *players = get_two_computers();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board(players);

        play_turn(player);

        if (has_won(player.token)){
            show_board(players);
            show_victory(player);
            free_computers(players);
            return;
        }
    }

    show_draw();
    free_computers(players);
}

void practice_mode() {
    show_mode_title("Practice Mode");

}


//TODO Extract these functions from this class

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

    return players;}

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
