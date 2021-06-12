#include <stdio.h>
#include <stdlib.h>
#include "../../gameMaster/gameMaster.h"
#include "../modeHandler/modeHandler.h"
#include "../otherHeaders/colors.h"

void show_mode_title(char *mode) {
    printf( PADDING "--%s--" PADDING "\n\n", mode);
}

void show_modes() {
    printf(PADDING "--Main Menu--" PADDING "\n\n");
    printf("1. Two player     (Player vs Player)\n");
    printf("2. One player     (Player vs Computer)\n");
    printf("3. Computer Fight (Computer vs Computer)\n");
    printf("4. Practice       (Player vs Player N games)\n");
    printf("0. Exit\n\n");
}

void show_victory(struct Player player) {
    printf("\n--- %s %s⬤ " RESET "has just won the game!---\n", player.name, player.color);
    printf(YELLOW "      --Congratulations!--\n\n" RESET);
}

void show_draw() {
    printf(PADDING "----GAME OVER----\n");
    printf(PADDING "    --DRAW--\n\n");
}

void show_player_turn(struct Player player){
    printf("%s's turn: %s⬤\n" RESET, player.name, player.color);
}

void show_enter_player_name(int player_number) {
    printf("Enter player%d name:\n> ", player_number);
}

void show_enter_your_choice(){
    printf("Enter your choice:\n> ");
}

void clear_console(){
    system("clear");
}