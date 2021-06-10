//
// Created by wolf on 6/10/21.
//

#include <stdio.h>
#include "../modeHandler/modeHandler.h"
#include "../../board/board.h"
#include "../gameLogicHandler/gameLogicHandler.h"
#include "../modeHandler/colors.h"

int get_column_computer_sabotage_victory(struct Player computer) {
    char enemy_token = computer.token == 'X' ? 'O' : 'X';

    //TODO extract !is_cell_empty(row + 1, column) to has_cell_under();

    //TODO extract checks to new functions

    // vertical_check : if enemy has 3 in a vertical column
    for (int column = 0; column < BOARD_SIZE; column++) {
        for (int row = BOARD_SIZE - 1; row >= 3; row--) {
            if (board[row][column] == enemy_token && board[row - 1][column] == enemy_token &&
                board[row - 2][column] == enemy_token && can_place_token_here(row - 3, column)) {
//                TODO add to -DEBUG
                printf(RED "SABOTAGING VERTICAL COLUMN: %d\n" RESET, column + 1);
                return column;
            }
        }
    }

    // horizontal_right_check: If enemy could have 4 in a row and |⬤|⬤|⬤|_| fourth is empty
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        for (int column = 0; column < BOARD_SIZE  - 3; column++) { //0-4  5 6 7
            if (board[row][column] == enemy_token &&
                board[row][column + 1] == enemy_token &&
                board[row][column + 2] == enemy_token &&
                is_cell_empty(row, column + 3) && !is_cell_empty(row + 1, column + 3)) {

                printf(RED "SABOTAGING: column: %d\n" RESET, column + 4);
                return column + 3;
            }
        }
    }

    // horizontal_left_check: If enemy could have 4 in a row and can |_|⬤|⬤|⬤| and first is empty
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        for (int column = BOARD_SIZE - 1; column >= 3; column--) { // 0 1 2| 3-7
            if (board[row][column] == enemy_token &&
                board[row][column - 1] == enemy_token &&
                board[row][column - 2] == enemy_token &&
                is_cell_empty(row, column -3) && !is_cell_empty(row + 1, column - 3)) {

                printf(RED "SABOTAGING: column: %d\n" RESET, column - 2);
                return column - 3;
            }
        }
    }

    // horizontal_left_hole_check: If enemy could have 4 in a row and |⬤|_|⬤|⬤| second is empty
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        for (int column = BOARD_SIZE - 1; column >= 3; column--) { //  0 1 2|3-7
            if (board[row][column] == enemy_token &&
                board[row][column - 1] == enemy_token &&
                is_cell_empty(row, column - 2) && !is_cell_empty(row + 1, column - 2) &&
                board[row][column - 3] == enemy_token) {

                printf(RED "SABOTAGING: column: %d\n" RESET, column - 1);
                return column - 2;
            }
        }
    }

    // horizontal_right_hole_check: If enemy could have 4 in a row and |⬤|⬤|_|⬤| fourth is empty
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        for (int column = 0; column < BOARD_SIZE  - 3; column++) { //0-4  5 6 7
            if (board[row][column] == enemy_token &&
                board[row][column + 1] == enemy_token &&
                is_cell_empty(row, column + 2) && !is_cell_empty(row + 1, column + 2) &&
                board[row][column + 3] == enemy_token) {

                printf(RED "SABOTAGING: column: %d\n" RESET, column + 3);
                return column + 2;
            }
        }
    }

    //                                                                                 | | | |X|
    //                                                                                 | | |⬤| |
    //                                                                                 | |⬤| | |
    // ascending_diagonal_check: if enemy could have 4 in a row in a diagonal position |⬤| | | |
    for (int row = BOARD_SIZE - 1; row >= 3; row--) {
        for (int column = 0; column < BOARD_SIZE - 3; column++) {
            if (board[row][column] == enemy_token && board[row - 1][column + 1] == enemy_token &&
                board[row - 2][column + 2] == enemy_token && can_place_token_here(row - 3, column + 3)){

                printf(RED "SABOTAGING ASC DIAGN: column: %d\n" RESET, column + 4);
                return column + 3;
            }
        }
    }

    //                                                                                 |X| | | |
    //                                                                                 | |⬤| | |
    //                                                                                 | | |⬤| |
    // descending_diagonal_check: if enemy could have 4 in a row in a diagonal position| | | |⬤|
    for (int row = BOARD_SIZE - 1; row >= 3; row--) {
        for (int column = BOARD_SIZE - 1; column >= 3; column--) {
            if (board[row][column] == enemy_token && board[row - 1][column - 1] == enemy_token &&
                board[row - 2][column - 2] == enemy_token && can_place_token_here(row - 3, column - 3)){

                printf(RED "SABOTAGING DESC DIAGN: column: %d\n" RESET, column - 2);
                return column - 3;
            }
        }
    }




    // horizontal_middle_two_check: if enemy has 2 next to each other |_|⬤|⬤|_| and empty surroundings
    for (int row = BOARD_SIZE - 1; row >= 0; row--) {
        for (int column = 1; column < BOARD_SIZE  - 3; column++) {
            if (is_cell_empty(row, column - 1) && !is_cell_empty(row+1, column - 1) &&   // |_|
                board[row][column] == enemy_token &&                                      // |⬤|
                board[row][column + 1] == enemy_token &&                                  // |⬤|
                is_cell_empty(row, column + 2) && !is_cell_empty(row+1, column + 2)) {   // |_|

                printf(RED "SABOTAGING: column: %d\n" RESET, column + 2);
                return column + 2;
            }
        }
    }

    return -1;
}
