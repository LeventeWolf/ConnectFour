cmake_minimum_required(VERSION 3.16.3)
project(ConnectFour C)

set(CMAKE_C_STANDARD 99)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    MESSAGE("\nDebug MODE\n")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG")
else ()
    MESSAGE("\nRelease MODE\n")
endif ()

include(CTest)

add_test (utest ${EXECUTABLE_OUTPUT_PATH}/src/main/utest)

add_subdirectory(src/board)
add_subdirectory(src/gameMaster)
add_subdirectory(src/handlers/inputHandler)
add_subdirectory(src/handlers/outputHandler)
add_subdirectory(src/handlers/modeHandler)
add_subdirectory(src/handlers/computerHandler)
add_subdirectory(src/handlers/gameLogicHandler)
add_subdirectory(src/main)

target_link_libraries(utest board)
target_link_libraries(utest gameMaster)
target_link_libraries(utest computerHandler)
target_link_libraries(utest inputHandler)
target_link_libraries(utest gameLogicHandler)
target_link_libraries(utest modeHandler)
