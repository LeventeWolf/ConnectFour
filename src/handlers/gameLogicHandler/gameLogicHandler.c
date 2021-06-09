#include <unistd.h>
#include <stdio.h>
#include "../../board/board.h"
#include "../outputHandler/outputHandler.h"
#include "../gameLogicHandler/gameLogicHandler.h"
#include "../inputHandler/inputHandler.h"

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

void play_human_turn(struct Player player) {
    int error_code;

    do {
        error_code = put_color_to_board(get_index_where_to_put(), player.token);

        if (error_code == 2) printf("The selected column is full!\n");

    } while (error_code != 1);
}


bool is_cell_empty(int i, int j) {
    if (board[i][j] == ' ') return true;

    return false;
}

bool is_column_full(int column_index) {
    if (board[0][column_index] != ' ') {
        return true;
    }

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

bool has_won(char color) {
    // horizontal_check
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE  - 3; j++) {
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
