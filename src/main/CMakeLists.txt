add_executable(main main.c ../handlers/otherHeaders/debug.h)
add_executable (utest utest.c ../board/utest-board.h)

target_link_libraries(utest cunit)

target_link_libraries(main gameMaster)
target_link_libraries(gameMaster board)
target_link_libraries(gameMaster modeHandler)
target_link_libraries(gameMaster inputHandler)
target_link_libraries(gameMaster outputHandler)