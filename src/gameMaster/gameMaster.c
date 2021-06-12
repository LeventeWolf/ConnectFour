#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "gameMaster.h"
#include "../handlers/modeHandler/modeHandler.h"
#include "../handlers/inputHandler/inputHandler.h"
#include "../handlers/outputHandler/outputHandler.h"
#include "../board/board.h"

#ifdef DEBUG
#define debug_print(format, ...) printf(format, __VA_ARGS__)
#else
#define debug_print(...)
#endif


void start() {
    srand ( time(NULL) );
    init();

    clear_console();

    show_title();
    main_menu();
}

void init() {
    init_modes();
}

void show_title() {
    printf(TITLE_PADDING "Connect Four" TITLE_PADDING "\n\n");
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
