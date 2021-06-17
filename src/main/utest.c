#include "CUnit/Basic.h"
#include <CUnit/CUnit.h>

static void test_init_board() {
    CU_ASSERT_TRUE(1);
}

static void test_decode() {
    CU_ASSERT_TRUE(1)
}

CU_TestInfo board_tests[] = {
        {"testing board initialization", test_init_board},
        {"decode a character",               test_decode},
        CU_TEST_INFO_NULL
};

CU_SuiteInfo board_test_suites[] = {
        {"Board tests", NULL, NULL, NULL, NULL,
         board_tests },
        CU_SUITE_INFO_NULL
};

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return -1;
    };
    if (CU_register_suites(board_test_suites) != CUE_SUCCESS) {
        return -1;
    };
    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}