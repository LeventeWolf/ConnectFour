#include <stdio.h>
#include <stdlib.h>
#include "../../gameMaster/gameMaster.h"
#include "../modeHandler/modeHandler.h"
#include "../otherHeaders/colors.h"
#include "../otherHeaders/debug.h"
#include "../../board/board.h"

void show_game_title() {
    printf(TITLE_PADDING "Connect Four" TITLE_PADDING "\n\n");
}

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

void show_new_line(){
    printf("\n");
}

void show_players_names_and_victories(struct Player *players){
    printf("%-5s : %d\n", players[0].name, players[0].victories);
    printf("%-5s : %d\n", players[1].name, players[1].victories);
}

void show_playing_until_n_victories(int number_of_victories){
    printf("    Playing until %d victories\n", number_of_victories);
}

void show_next_round(){
    printf(PADDING"--Next Round--\n");
}

void show_congratulations(){
    printf("      --Congratulations!--\n\n");
}

void show_practice_winner_player(struct Player player){
    printf("-- %s's %s%s%s has just won the practice! --\n", player.name, player.color, TOKEN, RESET);
}

void clear_console(){
    if (DEBUG) return;

    system("clear");
}