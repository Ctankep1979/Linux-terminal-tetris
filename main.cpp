#include <curses.h>

#include "game.hpp"


int main()
{
    Tetris::Game game{};
    game.run();
    return 0;
}