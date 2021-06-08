add_executable(main main.c)

target_link_libraries(main gameMaster)
target_link_libraries(gameMaster board)
target_link_libraries(gameMaster modeHandler)
target_link_libraries(gameMaster inputHandler)
target_link_libraries(gameMaster outputHandler)
