#include <CUnit/CUnit.h>
#include <malloc.h>
#include "utest-computerHandler.h"
#include "computerHandler.h"
#include "../../board/board.h"
#include "../otherHeaders/colors.h"
#include "../inputHandler/inputHandler.h"

void computerHandler_setup(){
    init_board();

}

void computerHandler_teardown(){
    free_board();

}

static void test_get_random_column_bounds() {
    int columns_to_avoid[] = {-1};

    for (int i = 1; i <= 100; ++i) {
        int result = get_random_column(columns_to_avoid);

        if (0 > result || result >= BOARD_SIZE) {
            CU_FAIL("Random column is out of bounds!")
            return;
        }
    }
}

static void test_get_random_column_and_avoid_one(){
    int columns_to_avoid[] = {1, -1};

    for (int i = 1; i <= 100; ++i) {
        int result = get_random_column(columns_to_avoid);

        if (result == 1) {
            free_board();
            CU_FAIL("Should have avoided column!")
            return;
        }
    }
}

static void test_vertical_sabotage_victory() {
    board[BOARD_SIZE - 3][0] = 'O';
    board[BOARD_SIZE - 2][0] = 'O';
    board[BOARD_SIZE - 1][0] = 'O';

    int expected = 0;
    int result = get_column_computer_sabotage_victory('X');

    CU_ASSERT_EQUAL(expected, result);
}

static void test_horizontal_sabotage_victory() {
    board[BOARD_SIZE - 1][2] = 'O';
    board[BOARD_SIZE - 1][1] = 'O';
    board[BOARD_SIZE - 1][0] = 'O';

    int expected = 3;
    int result = get_column_computer_sabotage_victory('X');

    CU_ASSERT_EQUAL(expected, result);
}


CU_TestInfo computerHandler_tests[] = {
        {"Testing get_random_column Bounds",        test_get_random_column_bounds},
        {"Testing get_random_column Avoid Columns", test_get_random_column_and_avoid_one},
        {"Testing vertical sabotage victory",       test_vertical_sabotage_victory},
        {"Testing horizontal sabotage victory",     test_horizontal_sabotage_victory},
        CU_TEST_INFO_NULL
};