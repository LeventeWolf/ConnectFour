#include <malloc.h>
#include "board.h"
#include "../gameMaster/gameMaster.h"
#include "../handlers/otherHeaders/colors.h"
#include "../handlers/modeHandler/modeHandler.h"

//       -- Board --
//
//      0 1 2 3 4 5 6 7
//   0 | | | | | | | | |
//   1 | | | | | | | | |
//   2 | | | | | | | | |
//   3 | | | | | | | | |
//   4 | | | | | | | | |
//   5 | | | | | | | | |
//   6 | | | | | | | | |
//   7 | | | | | | | | |
//     ─────────────────
//     /1 2 3 4 5 6 7 8\

char** board;

void init_board() {
    board = malloc(BOARD_SIZE * sizeof(char *));

    for (int i = 0; i < BOARD_SIZE; ++i) {
        board[i] = malloc(100 * sizeof(char));
    }

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j] = ' ';
        }
    }
}

void free_board(){
    for (int i = 0; i < BOARD_SIZE; ++i) {
        free(board[i]);
    }

    free(board);
}

void show_board(struct Player *players){
    printf( PADDING "-- Board --" PADDING "\n\n");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("        ");
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == 'X'){
                printf("|%s"TOKEN RESET, players[0].color);
            } else if(board[i][j] == 'O') {
                printf("|%s"TOKEN RESET, players[1].color);
            } else {
                printf("| ");
            }
        }
        printf("|\n");
    }

    printf("        ");
    for (int i = 0; i < BOARD_SIZE * 2 + 1; ++i) printf("─");

    printf("\n");

    printf("        ");
    printf("/");
    for (int i = 0; i < BOARD_SIZE; ++i) {
        if (i != BOARD_SIZE - 1) {
            printf("%d ", i+1);
        } else {
            printf("%d", i+1);
        }
    }
    printf("\\");
    printf("\n\n");

//    debug_print("DEBUG: Board printed successfully!\n");
}