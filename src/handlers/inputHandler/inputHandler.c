#include <stdlib.h>
#include "stdio.h"
#include "inputHandler.h"

int get_main_menu_choice(){

    int choice;

    show_enter_your_choice();
    while(scanf("%d" ,&choice) != 1 || !(1 <= choice && choice <= 4))
    {
        printf("Invalid choice!\n");
        show_enter_your_choice();
        while(getchar() != '\n');
    }

    return choice;
}

void show_enter_your_choice(){
    printf("Enter your choice:\n> ");
}
