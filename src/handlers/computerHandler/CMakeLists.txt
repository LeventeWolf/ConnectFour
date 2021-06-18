add_library(computerHandler computerHandler.c utest-computerHandler.c utest-computerHandler.h ../otherHeaders/debug.h)
target_include_directories(computerHandler PUBLIC .)