add_library(inputHandler inputHandler.c utest-inputHandler.c utest-inputHandler.h ../otherHeaders/debug.h)
target_include_directories(inputHandler PUBLIC .)