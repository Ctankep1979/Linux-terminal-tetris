#ifndef _H_TETRIS_
#define _H_TETRIS_

#include <array>

namespace Tetris
{   
    using namespace std;

    using enType = array<array<char,3>,3>;

    class Entity
    {
    private:
        
        enType& _entity;
        void
        cleanShape();
    public:
        Entity(enType& e);

        Entity(const Entity& e) = delete;

        Entity& operator=(Entity e) = delete;
        
        void
        createLshape(char s);
        void
        createTshape(char s);
        void
        createSshape(char s);
        void
        createSPshape(char s);
        void
        createIshape(char s);

        void
        rotateShape();

        enType
        getEntity();

    };
}

#endif