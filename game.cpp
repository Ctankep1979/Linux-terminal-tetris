#include "game.hpp"

int Tetris::Game::_key;
Ctankep::Keyboard Tetris::Game::_keyboard("/dev/input/event12");

std::mutex m;

namespace Tetris
{
    Game::Game()
    {
        _thread = thread(keyHandle);
        _thread.detach();
        _xpos = 0;
        _ypos = 3;
        
    }

    void
    Game::keyHandle()
    {
        int k;
        Game::_key = -1;
        while(true)
        {
            k = _keyboard.keyHold();
            m.lock();
            Game::_key = k >= 0 ? k : Game::_key;
            m.unlock();
        }
    }


    void
    Game::init()
    {

    }

    void
    Game::wait(uint16_t t)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(t));
    }

    void 
    Game::run()
    {
        int status;
        int y = _ypos;
        
        uint8_t timer = 0;

        while(1)
        {
            m.lock();
            switch (Game::_key)
            {
            case KEY_RIGHT:
                if(status == 1)
                    _ypos;
                else
                    _ypos++;
                break;
            case KEY_LEFT:
                if(status == -1)
                    _ypos;
                else
                    _ypos--;
                break;
            case KEY_SPACE:
                _draw.rotateEntity(_xpos,_ypos);
                break;

            case KEY_DOWN:
                timer+=8;
                break;
            
            default:
                break;
            }
            Game::_key = -1;
            m.unlock();
            status = _draw.update(_xpos,_ypos);
            if(status == -2)
            {
                _xpos = 1;
                _ypos = rand()%10 + 2;
            } 
             
            wait(50);
            
            if(timer++ > 20)
            {
                _xpos++;
                timer = 0;
            }
            
            
        }
    }


}