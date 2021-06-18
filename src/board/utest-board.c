#include <CUnit/CUnit.h>
#include "board.h"

static void test_init_board() {
    init_board();

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] != ' ') {
                free_board();
                CU_FAIL("Board initialize failed!")
            }
        }
    }

    free_board();
}


CU_TestInfo board_tests[] = {
        {"Testing board initialization", test_init_board},
        CU_TEST_INFO_NULL
};