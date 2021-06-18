#include <CUnit/CUnit.h>
#include "utest-computerHandler.h"
#include "computerHandler.h"
#include "../../board/board.h"

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
            CU_FAIL("Should have avoided column!")
            return;
        }
    }

}

CU_TestInfo computerHandler_tests[] = {
        {"Testing get_random_column Bounds", test_get_random_column_bounds},
        {"Testing get_random_column Avoid Columns", test_get_random_column_and_avoid_one},
        CU_TEST_INFO_NULL
};

CU_SuiteInfo computerHandler_test_suites[] = {
        {"ComputerHandler tests", NULL, NULL, NULL, NULL,
         computerHandler_tests },
        CU_SUITE_INFO_NULL
};