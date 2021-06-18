add_library(gameMaster gameMaster.c utest-gameMaster.c utest-gameMaster.h ../handlers/otherHeaders/debug.h)
target_include_directories(gameMaster PUBLIC .)