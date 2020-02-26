
#include "draw.hpp"


namespace Tetris
{
    
    Draw::Draw()
    {
        srand (time(NULL));
        clearConvas(_convas);
        addWall(_convas);

        createEntity();

        initscr();
        keypad(stdscr, TRUE);
        cbreak();
        noecho();
        curs_set(0);
        clear();
    }

    Draw::~Draw()
    {
        endwin();
    }

    void
    Draw::clearConvas(Conv& c)
    {
        for(int i=0;i<WIDTH;i++)
        {
            for(int j=0;j<LENGHT;j++)
            {
                c.at(i).at(j) = 0;
            }
        }
    }

    void
    Draw::addWall(Conv& c)
    {
        for(int i=0;i<LENGHT;i++)
        {
            c.at(i).front() = '#';
            c.at(i).back() = '#';

        }
        for(int i=0;i<WIDTH;i++)
        {
             c.back().at(i) = '#';
        }
    }

    void
    Draw::addEntity(int x, int y)
    {
        //createEntity();

        for(int i=0;i<_entity.size();i++)
        {
            for(int j=0;j<_entity.size();j++)
            {
                if(_entity.at(i).at(j) != 0)
                    _convas.at(i+x).at(j+y) = _entity.at(i).at(j);
            }
        }
    }

    bool
    Draw::checkBotom(int x, int y)
    {
        for(int i=0;i<_entity.size();i++)
        {
            for(int j=0;j<_entity.size();j++)
            {
                if(_entity.at(i).at(j) != 0)
                {
                    if(_convas.at(x+i+1).at(y+j) != 0)
                    {
                        return true;
                    }
                        
                }
            }
        }

        return false;
    }

    int
    Draw::checkSide(int x, int y)
    {   
        for(int i=0;i<_entity.size();i++)
        {
            for(int j=0;j<_entity.size();j++)
            {
                if(_entity.at(i).at(j) != 0)
                {
                    if(_convas.at(x+i).at(y+j+1) != 0)
                    {
                        return 1;
                    } else if(_convas.at(x+i).at(y+j-1) != 0)
                    {
                        return -1;
                    }
                        
                }
            }
        }
        return 0;
    }


    bool
    Draw::checkColision(enType e, int x, int y)
    {   
        for(int i=0;i<e.size();i++)
        {
            for(int j=0;j<e.size();j++)
            {
                if(e.at(i).at(j) != 0)
                {
                    if(_convas.at(x+i).at(y+j) != 0)
                    {
                        return true;
                    } 
                        
                }
            }
        }
        return false;
    }

    void
    Draw::drawEntity(int x, int y)
    {
        if(checkColision(_entity,x,y) == 0 )
        {
            for(int i=0;i<_entity.size();i++)
            {
                for(int j=0;j<_entity.size();j++)
                {
                    if(_entity.at(i).at(j) != 0)
                    {
                        mvaddch(x+i,y+j,_entity.at(i).at(j));
                    }
                }
            }
        }
    }

    void
    Draw::rotateEntity(int x, int y)
    {
        enType et = _tetris.getEntity();
        Entity en{et};
        en.rotateShape();
        
        if(!checkColision(et, x,y))
        {
            _tetris.rotateShape();
        }
  
    }

    void
    Draw::createEntity()
    {
        int token = rand() % 5;
        
        char ch = (char)(rand() % 26 + 65);

        switch (token)
        {
        case 0:
            _tetris.createIshape(ch);
            break;
        case 1:
            _tetris.createLshape(ch);
            break;
        case 2:
            _tetris.createSshape(ch);
            break;
        case 3:
            _tetris.createSPshape(ch);
            break;
        case 4:
            _tetris.createTshape(ch);
            break;
        
        default:
            break;
        }
    }


    void
    Draw::checkTetras()
    {
        Conv conv;
        clearConvas(conv);
        addWall(conv);

        int j = WIDTH-2;

        for(int i=WIDTH-2;i>0;i--)
        {
            auto r = std::find(_convas.at(i).begin(),_convas.at(i).end(), 0);
            if( r != std::end(_convas.at(i)))
            {
                conv.at(j--) = _convas.at(i);
            }
        }

        _convas = conv;

    }


    void
    Draw::drawWorld()
    {
        for(int i=0;i<WIDTH;i++)
        {
            for(int j=0;j<LENGHT;j++)
            {
                if(_convas.at(i).at(j) != 0)
                    mvaddch(i,j,_convas.at(i).at(j));
            }
        }
    }

    int
    Draw::update(int x, int y)
    {
        int status;

        if(checkBotom(x,y))
        {
            addEntity(x,y);
            status = -2;
            checkTetras();
            clear();
            drawWorld();
            refresh();
            createEntity();
            return status;
        } 
        status = checkSide(x,y);
        clear();
        drawWorld();
        drawEntity(x,y);
        refresh();

        return status;
    }

} // namespace name

