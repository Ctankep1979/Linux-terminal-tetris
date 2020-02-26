#ifndef _H_DRAW_
#define _H_DRAW_

#include <algorithm>
#include <array>
#include <ncurses.h>
#include <cstdint>

#include "tetris.hpp"

const int WIDTH = 20;
const int LENGHT = 20;

using namespace std;

using Conv = array<array<char,WIDTH>, LENGHT>;

namespace Tetris
{
    class Draw
    {
    private:
        Conv _convas;
        Tetris::enType _entity;

        Tetris::Entity _tetris{_entity};

        void
        createEntity();

    public:
        Draw();

        ~Draw();

        void
        drawWorld();

        void
        addEntity(int x, int y);

        void
        drawEntity(int x, int y);

        void
        rotateEntity(int x, int y);

        bool
        checkBotom(int x, int y);

        int
        checkSide(int x, int y);

        bool
        checkColision(enType e, int x, int y);

        void
        clearConvas(Conv& c);

        void
        addWall(Conv& c);

        int
        update(int x, int y);

        void
        checkTetras();

    

    }; 
} // namespace name




#endif