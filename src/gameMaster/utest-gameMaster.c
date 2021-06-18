#include <CUnit/CUnit.h>
#include "utest-gameMaster.h"

static void test_gameMaster() {
//    CU_FAIL("Not implemented yet")
}

CU_TestInfo gameMaster_tests[] = {
        {"Testing GameMaster", test_gameMaster},
        CU_TEST_INFO_NULL
};

CU_SuiteInfo gameMaster_test_suites[] = {
        {"GameMaster tests", NULL, NULL, NULL, NULL,
         gameMaster_tests },
        CU_SUITE_INFO_NULL
};