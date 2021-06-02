cmake_minimum_required(VERSION 3.19)
project(ConnectFour C)

set(CMAKE_C_STANDARD 99)

add_executable(ConnectFour src/main.c src/board/board.c src/board/board.h src/gamemaster/gameMaster.c src/gamemaster/gameMaster.h src/handlers/modeHandler/modeHandler.c src/handlers/modeHandler/modeHandler.h src/handlers/inputHandler/inputHandler.c src/handlers/inputHandler/inputHandler.h)