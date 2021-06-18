add_library(board board.c board.h utest-board.c utest-board.h ../handlers/otherHeaders/debug.h)

target_include_directories(board PUBLIC .)