#include <stdio.h>
#include "modeHandler.h"
#include "../../gamemaster/gameMaster.h"

void show_modes(){
    printf("1. Two player     (Player vs Player)\n");
    printf("2. One player     (Player vs Computer)\n");
    printf("3. Computer Fight (Computer vs Computer)\n");
    printf("4. Practice       (Player vs Player N games)\n   ");
    printf("0. Exit\n   ");
}

void init_modes(){
    MODES[0] = two_player_mode;
    MODES[1] = one_player_mode;
    MODES[2] = computer_vs_computer_mode;
    MODES[3] = practice_mode;
}

int play_mode(int mode){
    if (mode == 0) return 0;

    (*MODES[mode - 1])();

    return 1;
}

void show_mode_title(char* mode){
    printf("\n" PADDING "--%s--" PADDING "\n", mode);
}

void two_player_mode() {
    show_mode_title("Two Player Mode");
}

void one_player_mode(){
    show_mode_title("One Player Mode");

}

void computer_vs_computer_mode(){
    show_mode_title("Computer vs Computer Mode");

}

void practice_mode(){
    show_mode_title("Practice Mode");

}