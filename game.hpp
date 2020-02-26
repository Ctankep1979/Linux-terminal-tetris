#ifndef _H_GAME_
#define _H_GAME_

#include <chrono>
#include <thread>
#include <mutex>

#include "draw.hpp"
#include "Keyboard.hpp"

namespace Tetris
{
    class Game
    {
    private:

        std::thread _thread;
        Draw _draw;

        static
        Ctankep::Keyboard _keyboard;

        int _xpos;
        int _ypos;
        
        static int _key;

        static void
        keyHandle();

        void
        init();

        void
        wait(uint16_t t);

    public:

        explicit
        Game();
        
        Game&
        operator=(Game& g) = delete;

        void run();

        

    }; 
}




#endif