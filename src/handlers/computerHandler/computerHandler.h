#ifndef CONNECTFOUR_COMPUTERHANDLER_H
#define CONNECTFOUR_COMPUTERHANDLER_H

/*
 * Get random column from columns that are okay.
 * NOT OK Columns: if we prepare enemy victory.
 * If all columns are not ok just get a random
 */
int get_random_column(int *columns_to_avoid);

int get_column_computer_sabotage_victory(char token);

int get_computer_winner_column(struct Player player);

int *get_computer_columns_to_avoid(struct Player computer);

#endif //CONNECTFOUR_COMPUTERHANDLER_H
