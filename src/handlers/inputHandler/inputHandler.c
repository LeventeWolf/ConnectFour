#include <malloc.h>
#include "stdio.h"
#include "inputHandler.h"
#include "../../board/board.h"

int get_main_menu_choice(){
    int choice;

    show_enter_your_choice();
    while(scanf("%d" ,&choice) != 1 || !(0 <= choice && choice <= 4))
    {
        printf("Invalid choice!\n");
        show_enter_your_choice();
        while(getchar() != '\n');
    }

    return choice;
}

int get_index_where_to_put(){
    int choice;

    show_enter_your_choice();
    while(scanf("%d" ,&choice) != 1 || !(1 <= choice && choice <= BOARD_SIZE))
    {
        printf("Invalid choice!\n");
        show_enter_your_choice();
        while(getchar() != '\n');
    }

    return choice - 1;
}

char** get_two_player_name(){
    char **player_names = malloc(2 * sizeof(char *));
    player_names[0] = malloc(100 * sizeof(char));
    player_names[1] = malloc(100 * sizeof(char));


    show_enter_player_name(1);
    scanf("%99s", player_names[0]);

    show_enter_player_name(2);
    scanf("%99s", player_names[1]);

    return player_names;
}

char* get_player_name(){
    char *player_name = malloc(100 * sizeof(char));
    show_enter_player_name(1);
    scanf("%99s", player_name);

    return player_name;
}

void show_enter_player_name(int player_number) {
    printf("Enter player%d name:\n> ", player_number);
}

void show_enter_your_choice(){
    printf("Enter your choice:\n> ");
}
