#include "tetris.hpp"

namespace Tetris
{

    Entity::Entity(enType& e): _entity{e}{}

    // Entity::Entity(const Entity& e): _entity{e._entity}
    // {
        
    // }

    // Entity&
    // Entity::operator=(Entity e)
    // {
        
    // }

    void
    Entity::cleanShape()
    {
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                _entity.at(i).at(j) = 0;
            }
        }
    }

    enType
    Entity::getEntity()
    {
        enType en = _entity;
        return en;
    }

    void
    Entity::createIshape(char s)
    {
        cleanShape();
        _entity.at(0).at(1) = s;
        _entity.at(1).at(1) = s;
        _entity.at(2).at(1) = s;

    }

    void
    Entity::createLshape(char s)
    {
        cleanShape();
        _entity.at(0).at(0) = s;
        _entity.at(1).at(0) = s;
        _entity.at(2).at(0) = s;
        _entity.at(2).at(1) = s;
    }

    void
    Entity::createTshape(char s)
    {
        cleanShape();
        _entity.at(0).at(0) = s;
        _entity.at(0).at(1) = s;
        _entity.at(0).at(2) = s;
        _entity.at(1).at(1) = s;
        _entity.at(2).at(1) = s;
    }

    void
    Entity::createSshape(char s)
    {
        cleanShape();
        _entity.at(0).at(2) = s;
        _entity.at(1).at(1) = s;
        _entity.at(1).at(2) = s;
        _entity.at(2).at(1) = s;

    }

    void
    Entity::createSPshape(char s)
    {
        cleanShape();
        _entity.at(0).at(0) = s;
        _entity.at(1).at(0) = s;
        _entity.at(1).at(1) = s;
        _entity.at(2).at(1) = s;

    }

    void
    Entity::rotateShape()
    {
        enType _etemp;

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                _etemp.at(2-j).at(i) = _entity.at(i).at(j); 
            }
        }
        _entity = _etemp;
    }

}