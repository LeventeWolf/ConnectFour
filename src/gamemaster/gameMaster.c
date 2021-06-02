#include <stdio.h>
#include "gameMaster.h"
#include "../handlers/modeHandler/modeHandler.h"
#include "../handlers/inputHandler/inputHandler.h"

void start() {
    show_title();
    main_menu();
}

void show_title() {
    printf(TITLE_PADDING "Connect Four" TITLE_PADDING "\n");
}

void main_menu() {
    printf(PADDING "--Main Menu--" PADDING "\n");
    show_modes();
    get_main_menu_choice();
}
