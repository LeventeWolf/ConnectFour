#include "../../board/board.h"

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
