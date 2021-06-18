#include "CUnit/Basic.h"
#include "../board/utest-board.h"
#include "../gameMaster/utest-gameMaster.h"
#include "../handlers/computerHandler/utest-computerHandler.h"
#include <CUnit/CUnit.h>

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) { return -1; }

    if (CU_register_suites(board_test_suites) != CUE_SUCCESS) {return -1;}
    if (CU_register_suites(gameMaster_test_suites) != CUE_SUCCESS) {return -1;}
    if (CU_register_suites(computerHandler_test_suites) != CUE_SUCCESS) {return -1;}


    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}