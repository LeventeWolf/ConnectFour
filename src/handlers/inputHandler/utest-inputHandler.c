#include <CUnit/CUnit.h>
#include <malloc.h>
#include "inputHandler.h"
#include "../modeHandler/modeHandler.h"

static struct Player *computers;

/* run at the start of each test */
void inputHandler_setup() {
    computers = get_two_computers();
}

/* run at the end of each test */
void inputHandler_teardown() {
    free_computers(computers);
}

static void test_get_two_computers_tokens() {
    if (computers[0].token != 'X' || computers[1].token != 'O') {
        CU_FAIL("Computer's token is not initialized!")
    }
}

static void test_get_two_computers_name() {
    if (strcmp(computers[0].name, "Computer_Bobby") != 0 || strcmp(computers[1].name, "Computer_Alice") != 0) {
        CU_FAIL("Computer's name is not initialized!")
    }
}

static void test_get_two_computers_is_human() {
    if (computers[0].is_human || computers[1].is_human) {
        CU_FAIL("Computer is not initialized!")
    }
}

CU_TestInfo inputHandler_tests[] = {
        {"Testing get_two_computers_tokens",     test_get_two_computers_tokens},
        {"Testing get_two_computers_name",       test_get_two_computers_name},
        {"Testing get_two_computers_is_human",   test_get_two_computers_is_human},
        CU_TEST_INFO_NULL
};