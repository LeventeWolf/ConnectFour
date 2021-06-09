#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "modeHandler.h"
#include "../../gameMaster/gameMaster.h"
#include "../inputHandler/inputHandler.h"
#include "../outputHandler/outputHandler.h"
#include "../../board/board.h"
#include "colors.h"

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

    (*MODES[mode - 1])();

    return 1;
}

void play_turn(struct Player player) {
    show_player_turn(player);

    if (player.is_human) {
        play_human_turn(player);
    } else {
        play_computer_turn(player);
    }
}

void play_computer_turn(struct Player player) {
    time_t t;
    srand((unsigned) time(&t));

    int error_code;
    int random_column;

    do {
        random_column = rand() % BOARD_SIZE;
        error_code = put_color_to_board(random_column, player.token);
    } while (error_code != 1);

    printf("> %d\n", random_column + 1);

}

int get_random_column() {


    return 0;
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
            show_victory(player.name);
            return;
        }
    }

    show_draw();
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
            show_victory(player.name);
            return;
        }
    }

    show_draw();
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
            show_victory(player.name);
            return;
        }
    }

    show_draw();
}

void practice_mode() {
    show_mode_title("Practice Mode");

}

//TODO Extract these functions from this class

bool is_cell_empty(int i, int j) {
    if (board[i][j] == ' ') return true;

    return false;
}

int put_color_to_board(int column_index, char token) {
    if (is_column_full(column_index)) return 2;

    for (int row = BOARD_SIZE - 1; row >= 0; --row) {
        if (is_cell_empty(row, column_index)) {
            board[row][column_index] = token;
            break;
        }
    }

    return 1;
}

bool is_column_full(int column_index) {
    if (board[0][column_index] != ' ') {
        return true;
    }

    return false;
}

bool has_won(char color) {
    // horizontal_check
    for (int j = 0; j < BOARD_SIZE - 3; j++) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (board[i][j] == color && board[i][j + 1] == color &&
                board[i][j + 2] == color && board[i][j + 3] == color) {
                return true;
            }
        }
    }

    // vertical_check
    for (int i = 0; i < BOARD_SIZE - 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == color && board[i + 1][j] == color &&
                board[i + 2][j] == color && board[i + 3][j] == color) {
                return true;
            }
        }
    }

    // ascending_diagonal_check
    for (int i = 3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 3; j++) {
            if (board[i][j] == color && board[i - 1][j + 1] == color &&
                board[i - 2][j + 2] == color && board[i - 3][j + 3] == color)
                return true;
        }
    }

    // descending_diagonal_check
    for (int i = 3; i < BOARD_SIZE; i++) {
        for (int j = 3; j < BOARD_SIZE; j++) {
            if (board[i][j] == color && board[i - 1][j - 1] == color &&
                board[i - 2][j - 2] == color && board[i - 3][j - 3] == color)
                return true;
        }
    }

    return false;
}

//TODO Extract these functions from this class

struct Player *get_two_players() {
    char **player_names = get_two_player_name();
    struct Player player1;
    struct Player player2;

    player1.name = player_names[0];
    player2.name = player_names[1];

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

    player1.name = "Computer1";
    player2.name = "Computer2";

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
