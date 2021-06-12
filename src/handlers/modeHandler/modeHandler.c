#include <stdio.h>
#include "modeHandler.h"
#include "../inputHandler/inputHandler.h"
#include "../outputHandler/outputHandler.h"
#include "../../board/board.h"
#include "../gameLogicHandler/gameLogicHandler.h"
#include "../../gameMaster/gameMaster.h"
#include "../otherHeaders/colors.h"


void init_modes() {
    MODES[0] = two_player_mode;
    MODES[1] = one_player_mode;
    MODES[2] = computer_vs_computer_mode;
    MODES[3] = practice_mode;
}

int play_mode(int mode) {
    if (mode == 0) return 0;

    clear_console();

    (*MODES[mode - 1])();


    return 1;
}

void two_player_mode() {
    show_mode_title("Two Player Mode");

    struct Player *players = get_two_players();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board(players);

        play_turn(player);

        if (has_won(player.token)){
            show_board(players);
            show_victory(player);
            free_players(players);
            return;
        }
    }

    show_board(players);
    show_draw();
    free_players(players);
}

void one_player_mode() {
    show_mode_title("One Player Mode");

    struct Player *players = get_one_player_and_computer();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board(players);

        play_turn(player);

        if (has_won(player.token)){
            show_board(players);
            show_victory(player);
            free_human_and_computer(players);
            return;
        }
    }

    show_board(players);
    show_draw();
    free_human_and_computer(players);
}

void computer_vs_computer_mode() {
    show_mode_title("Computer Vs Computer Mode");

    struct Player *players = get_two_computers();

    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        struct Player player = players[i % 2];

        show_board(players);

        play_turn(player);

        if (has_won(player.token)){
            show_board(players);
            show_victory(player);
            free_computers(players);
            return;
        }
    }

    show_board(players);
    show_draw();
    free_computers(players);
}

void practice_mode() {
    show_mode_title("Practice Mode");

    int number_of_victories = get_number_of_victories();
    printf("\n");
    struct Player *players = get_two_players();

    players[0].victories = 0;
    players[1].victories = 0;


    while (players[0].victories != number_of_victories && players[1].victories != number_of_victories) {
        printf("    Playing untill %d victories\n", number_of_victories);
        printf("%-5s : %d\n", players[0].name, players[0].victories);
        printf("%-5s : %d\n", players[1].name, players[1].victories);

        bool hasWon = false;


        for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
            struct Player player = players[i % 2];

            show_board(players);

            play_turn(player);

            if (has_won(player.token)) {
                show_board(players);
                show_victory(player);
                players[i % 2].victories += 1;
                hasWon = true;
                init_board();
                break;
            }
        }

        if (!hasWon) {
            show_board(players);
            show_draw();
            init_board();
        }

        if (players[0].victories != number_of_victories && players[1].victories != number_of_victories)
            printf(PADDING"--Next Round--\n");
    }


    if (players[0].victories == number_of_victories) {
        printf("    Playing untill %d victories\n\n", number_of_victories);
        printf("%-5s : %d\n", players[0].name, players[0].victories);
        printf("%-5s : %d\n\n", players[1].name, players[1].victories);
        printf("-- %s's %s%s%s has just won the practice! --\n", players[0].name, players[0].color, TOKEN, RESET);
    } else {
        printf( "   Playing untill %d victories\n\n", number_of_victories);
        printf("%-5s : %d\n", players[0].name, players[0].victories);
        printf("%-5s : %d\n\n", players[1].name, players[1].victories);
        printf("-- %s's %s%s%s has just won the practice! --\n", players[1].name, players[1].color, TOKEN, RESET);
    }
    printf("      --Congratulations!--\n\n");

    free_players(players);
}
