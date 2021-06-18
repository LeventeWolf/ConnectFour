#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "gameMaster.h"
#include "../handlers/modeHandler/modeHandler.h"
#include "../handlers/inputHandler/inputHandler.h"
#include "../handlers/outputHandler/outputHandler.h"
#include "../board/board.h"

void start() {
    init();

    show_game_title();
    main_menu();
}

void init() {
    srand ( time(NULL) );

    clear_console();

    init_modes();
}

void main_menu() {
    while(true){
        show_modes();
        init_board();
        if (play_mode(get_main_menu_choice()) == 0) break;
        free_board();
    }

    free_board();
}
