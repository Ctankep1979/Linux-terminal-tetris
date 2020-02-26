cmake_minimum_required(VERSION 3.7)
project(tetris C CXX)

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)

include_directories(${CURSES_INCLUDE_DIRS})

add_executable(tetris main.cpp draw.cpp tetris.cpp game.cpp Keyboard.cpp)
target_link_libraries(tetris ${CURSES_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

