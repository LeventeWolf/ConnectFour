#include <unistd.h>
#include <stdio.h>
#include <malloc.h>
#include "../../board/board.h"
#include "../outputHandler/outputHandler.h"
#include "../gameLogicHandler/gameLogicHandler.h"
#include "../inputHandler/inputHandler.h"
#include "../computerHandler/computerHandler.h"
#include "../otherHeaders/debug.h"

void print_array(int* array);

void play_turn(struct Player player) {
    show_player_turn(player);

    if (player.is_human) {
        play_human_turn(player);
    } else {
        play_computer_turn(player);
//        sleep(1);
    }

    //TODO add -CLEAR flag
    clear_console();
}

void play_computer_turn(struct Player computer) {
    // easy win
    int winner_column = get_computer_winner_column(computer);
    if (winner_column != -1){
        put_color_to_board(winner_column, computer.token);
        return;
    }


    // TODO don't prepare enemy win
    // dont prepare enemy win (avoid putting under enemy win condition)
    int *columns_to_avoid = get_computer_columns_to_avoid(computer);
    if (DEBUG) print_array(columns_to_avoid);

    // sabotage enemy victory
    int try_sabotage_victory = get_column_computer_sabotage_victory(computer.token);
    if (try_sabotage_victory != -1){
        put_color_to_board(try_sabotage_victory, computer.token);
        free(columns_to_avoid);
        return;
    }




    // put randomly
    int error_code;
    int random_column;
    do {
        random_column = get_random_column(columns_to_avoid);
        error_code = put_color_to_board(random_column, computer.token);
    } while (error_code != 1);

    free(columns_to_avoid);
}

void print_array(int *array) {
    printf("columns to avoid: ");

    if (get_array_size(array) == 0) {
        printf("none\n");
        return;
    }

    for (int i = 0; array[i] != -1; ++i) {
        printf("%d ", array[i] + 1);
     }
    printf("\n");
}

void play_human_turn(struct Player player) {
    int error_code;

    do {
        error_code = put_color_to_board(get_index_where_to_put(), player.token);

        if (error_code == 2) printf("The selected column is full!\n");

    } while (error_code != 1);
}

bool is_cell_empty(int i, int j) {
    if (i < 0 || j < 0 || i >= BOARD_SIZE || j >= BOARD_SIZE) return false;

    return board[i][j] == ' ' ? true : false;
}

bool is_column_full(int column_index) {
    if (board[0][column_index] != ' ') {
        return true;
    }

    return false;
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

    //if cell under is empty
    if (is_cell_empty(i + 1, j)) return false;

    return true;
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

int get_array_size(const int *array){
    int size = 0;

    for (int i = 0; array[i] != -1; ++i) {
        size++;
    }

    return size;
}

bool contains(const int *array, const int column){
    if (get_array_size(array) == 0) return false;

    for (int i = 0; array[i] != -1; ++i) {
        if (column == array[i]) return true;
    }

    return false;
}

int number_of_not_full_columns(){
    int columns = 0;

    for (int j = 0; j < BOARD_SIZE; ++j) {
        if (!is_column_full(j)) columns++;
    }

    return columns;
}

/*
 * create int[] array with -1 default values
 */
int *create_my_array(int size, int default_value){
    int *array = malloc(size * sizeof(int));

    for (int i = 0; i < size; ++i) {
        array[i] = default_value;
    }

    return array;
}