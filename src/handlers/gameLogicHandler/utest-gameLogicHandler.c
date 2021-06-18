#include <CUnit/CUnit.h>
#include "../modeHandler/modeHandler.h"
#include "../../board/board.h"
#include "gameLogicHandler.h"

/* run at the start of each test */
void gameLogicHandler_setup() {
    init_board();
}

void gameLogicHandler_teardown() {
    free_board();
}

static void test_is_cell_empty_all_cells_are_empty() {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            CU_ASSERT_TRUE(is_cell_empty(i, j))
        }
    }
}


static void test_is_cell_empty_cell_is_not_empty() {
    board[2][2] = 'X';

    bool expected = false;
    bool result = is_cell_empty(2, 2);

    CU_ASSERT_EQUAL(expected, result);
}


CU_TestInfo gameLogicHandler_tests[] = {
        {"Testing is_cell_empty() with all cells inited emtpy",     test_is_cell_empty_all_cells_are_empty},
        {"Testing is_cell_empty() with a not empty cell",           test_is_cell_empty_cell_is_not_empty},
        CU_TEST_INFO_NULL
};

//CU_SuiteInfo gameLogicHandler_test_suites[] = {
//    {"GameLogicHandler Tests", NULL, NULL, CU_TEST_SETUP, CU_TEST_TEARDOWN,
//                gameLogicHandler_tests},
//    CU_SUITE_INFO_NULL
//};