#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "modeHandler.h"
#include "../../gamemaster/gameMaster.h"
#include "../inputHandler/inputHandler.h"
#include "../../board/board.h"

void show_modes() {
    printf(PADDING "--Main Menu--" PADDING "\n");
    printf("1. Two player     (Player vs Player)\n");
    printf("2. One player     (Player vs Computer)\n");
    printf("3. Computer Fight (Computer vs Computer)\n");
    printf("4. Practice       (Player vs Player N games)\n");
    printf("0. Exit\n");
}

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

void show_mode_title(char *mode) {
    printf("\n" PADDING "--%s--" PADDING "\n", mode);
}


//TODO Extract player struct from this class!
struct Player {
    char *name;
    char color;
};

struct Player *get_two_players() {
    char **player_names = get_two_player_name();
    struct Player player1;
    struct Player player2;

    player1.name = player_names[0];
    player2.name = player_names[1];

    player1.color = 'X';
    player2.color = 'O';

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

    player1.color = 'X';
    player2.color = 'O';

    struct Player *players = malloc(2 * sizeof(struct Player));
    players[0] = player1;
    players[1] = player2;

    return players;
}


void two_player_mode() {
    show_mode_title("Two Player Mode");

    struct Player *players = get_two_players();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board();

        printf("%s's turn: %c\n", player.name, player.color);

        int error_code = put_color_to_board(get_index_where_to_put(), player.color);

        while (error_code != 1) {
            if (error_code == 2) printf("The selected column is full!\n");

            error_code = put_color_to_board(get_index_where_to_put(), player.color);
        }

        if (has_won(player.color)){
            show_board();

            printf("\n" PADDING "----%s has just won the game!---\n", player.name);
            printf(PADDING "      --Congratulations!--\n\n");
            return;
        }

    }

    printf(PADDING "----GAME OVER----\n");
    printf(PADDING "    --DRAW--\n\n");

}

void one_player_mode() {
    show_mode_title("One Player Mode");

    struct Player *players = get_one_player_and_computer();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board();

        printf("%s's turn: %c\n", player.name, player.color);

        int error_code = put_color_to_board(get_index_where_to_put(), player.color);

        while (error_code != 1) {
            if (error_code == 2) printf("The selected column is full!\n");

            error_code = put_color_to_board(get_index_where_to_put(), player.color);
        }

        if (has_won(player.color)){
            show_board();

            printf("\n" PADDING "----%s has just won the game!---\n", player.name);
            printf(PADDING "      --Congratulations!--\n\n");
            return;
        }

    }

    printf(PADDING "----GAME OVER----\n");
    printf(PADDING "    --DRAW--\n\n");
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

bool is_cell_empty(int i, int j) {
    if (board[i][j] == ' ') return true;

    return false;
}

int put_color_to_board(int column_index, char color) {
    if (is_column_full(column_index)) return 2;

    for (int row = BOARD_SIZE - 1; row >= 0; --row) {
        if (is_cell_empty(row, column_index)) {
            board[row][column_index] = color;
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

void computer_vs_computer_mode() {
    show_mode_title("Computer vs Computer Mode");

}

void practice_mode() {
    show_mode_title("Practice Mode");

}