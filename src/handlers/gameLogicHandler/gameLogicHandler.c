#include <unistd.h>
#include <stdio.h>
#include <colors.h>
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

//    clear_console();
}

void play_computer_turn(struct Player computer) {
    int error_code;
    int random_column;

    int try_sabotage_victory = get_column_computer_sabotage_victory(computer);

    if (try_sabotage_victory){
        put_color_to_board(try_sabotage_victory, computer.token);
    }  else {
        do {
            random_column = get_random_column();
            error_code = put_color_to_board(random_column, computer.token);
        } while (error_code != 1);
    }

}


int get_column_computer_sabotage_victory(struct Player computer) {
    char enemy_token = computer.token == 'X' ? 'O' : 'X';

    // vertical_check : if has 3 in a row in vertical position
    for (int column = 0; column < BOARD_SIZE; column++) {
        for (int row = BOARD_SIZE - 1; row >= 4; row--) {
            if (board[row][column] == enemy_token && board[row - 1][column] == enemy_token &&
                board[row - 2][column] == enemy_token && can_place_token_here(row - 3, column)) {
//                TODO add to -DEBUG
//                printf(RED "SABOTAGING VERTICAL COLUMN: %d\n" RESET, column + 1);
                return column;
            }
        }
    }


//    // horizontal_right_check
//    for (int i = 0; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE  - 3; j++) {
//            if (board[i][j] == enemy_token && board[i][j + 1] == enemy_token &&
//                    can_place_token_here(i, j + 2)) {
//                if (can_place_token_here(i, j + 2)) {
//                    sleep(2);
//                    printf("can place token here column: %d\n", j + 2);
//
//                }
//                printf("SABOTAGING: column: %d\n", j + 2);
//                return j + 2;
//            }
//        }
//    }
//
//    // horizontal_left_check
//
//

//
//    // ascending_diagonal_check
//    for (int i = 3; i < BOARD_SIZE; i++) {
//        for (int j = 0; j < BOARD_SIZE - 3; j++) {
//            if (board[i][j] == enemy_token && board[i - 1][j + 1] == enemy_token &&
//                board[i - 2][j + 2] == enemy_token && can_place_token_here(i - 3, j + 3))
//                return j;
//        }
//    }
//
//    // descending_diagonal_check
//    for (int i = 3; i < BOARD_SIZE; i++) {
//        for (int j = 3; j < BOARD_SIZE; j++) {
//            if (board[i][j] == enemy_token && board[i - 1][j - 1] == enemy_token &&
//                board[i - 2][j - 2] == enemy_token && can_place_token_here(i - 3, j - 3))
//                return j - 3;
//        }
//    }

    return 0;
}


bool can_place_token_here(int i, int j){
    //if row and column are out of the board
    if (i < 0 || j < 0 || i >= BOARD_SIZE || j >= BOARD_SIZE) return false;

    //if column is full
    if (is_column_full(j)) return false;

    //if cell is already taken
    if (!is_cell_empty(i, j)) return false;

    //if not first row and has token under
    if (i != 0 && is_cell_empty(i+1, j)) return false;

    return true;
}

void play_human_turn(struct Player player) {
    int error_code;

    do {
        error_code = put_color_to_board(get_index_where_to_put(), player.token);

        if (error_code == 2) printf("The selected column is full!\n");

    } while (error_code != 1);
}


bool is_cell_empty(int i, int j) {
    return board[i][j] == ' ' ? true : false;
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

bool has_won(char token) {
    // horizontal_check
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE  - 3; j++) {
            if (board[i][j] == token && board[i][j + 1] == token &&
                board[i][j + 2] == token && board[i][j + 3] == token) {
                return true;
            }
        }
    }

    // vertical_check
    for (int i = 0; i < BOARD_SIZE - 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == token && board[i + 1][j] == token &&
                board[i + 2][j] == token && board[i + 3][j] == token) {
                return true;
            }
        }
    }

    // ascending_diagonal_check
    for (int i = 3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE - 3; j++) {
            if (board[i][j] == token && board[i - 1][j + 1] == token &&
                board[i - 2][j + 2] == token && board[i - 3][j + 3] == token)
                return true;
        }
    }

    // descending_diagonal_check
    for (int i = 3; i < BOARD_SIZE; i++) {
        for (int j = 3; j < BOARD_SIZE; j++) {
            if (board[i][j] == token && board[i - 1][j - 1] == token &&
                board[i - 2][j - 2] == token && board[i - 3][j - 3] == token)
                return true;
        }
    }

    return false;
}
