#include <malloc.h>
#include "board.h"
#include "../gamemaster/gameMaster.h"

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


void show_board(){
    printf( PADDING "-- Board --" PADDING "\n");

    for (int i = 0; i < BOARD_SIZE; ++i) {
        printf("        ");
        for (int j = 0; j < BOARD_SIZE; ++j) {
            printf("|%c", board[i][j]);
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
    printf("\n");
}