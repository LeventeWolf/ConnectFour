add_library(modeHandler modeHandler.c colors.h ../gameLogicHandler/gameLogicHandler.c ../gameLogicHandler/gameLogicHandler.h)
target_include_directories(modeHandler PUBLIC .)