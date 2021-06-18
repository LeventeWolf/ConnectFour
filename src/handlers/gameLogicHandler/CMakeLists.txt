add_library(gameLogicHandler gameLogicHandler.c gameLogicHandler.h utest-gameLogicHandler.c utest-gameLogicHandler.h)
target_include_directories(gameLogicHandler PUBLIC .)

target_link_libraries(gameLogicHandler inputHandler)