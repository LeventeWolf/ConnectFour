#include <CUnit/CUnit.h>
#include "modeHandler.h"

static void test_init_modes() {
    init_modes();

    if (MODES[0] != two_player_mode) CU_FAIL("Two Player Mode is not initialized!")
    if (MODES[1] != one_player_mode) CU_FAIL("One Player Mode is not initialized!")
    if (MODES[2] != computer_vs_computer_mode) CU_FAIL("Computer Vs Computer Mode is not initialized!")
    if (MODES[3] != practice_mode) CU_FAIL("Practice Mode is not initialized!")
}


CU_TestInfo modeHandler_tests[] = {
        {"Testing mode initializations",     test_init_modes},
        CU_TEST_INFO_NULL
};