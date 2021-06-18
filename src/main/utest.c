#include "CUnit/Basic.h"
#include "../board/utest-board.h"
#include "../gameMaster/utest-gameMaster.h"
#include "../handlers/computerHandler/utest-computerHandler.h"
#include <CUnit/CUnit.h>
#include <utest-gameLogicHandler.h>
#include <utest-inputHandler.h>
#include <utest-modeHandler.h>

CU_SuiteInfo connect_four_suites[] = {
        {"board", NULL, NULL, NULL, NULL,board_tests},
        {"gameMaster", NULL, NULL, NULL, NULL, gameMaster_tests},
        {"computerHandler", NULL, NULL, NULL, NULL, computerHandler_tests},
        {"gameLogicHandlerTests", NULL, NULL, gameLogicHandler_setup, gameLogicHandler_teardown, gameLogicHandler_tests},
        {"inputHandlerTests", NULL, NULL, inputHandler_setup, inputHandler_teardown, inputHandler_tests},
        {"modeHandlerTest", NULL, NULL, NULL, NULL, modeHandler_tests},
        CU_SUITE_INFO_NULL
};

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) { return -1; }

    if (CU_register_suites(connect_four_suites) != CUE_SUCCESS) {return -1;}

    CU_basic_set_mode(CU_BRM_NORMAL);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}