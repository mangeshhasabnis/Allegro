#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H

#include <list>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class CGameObject
{
    public:
        CGameObject();
        virtual ~CGameObject();
        virtual void Draw();
    protected:
        int xlocation;
        int ylocation;
        ALLEGRO_BITMAP *spaceShipBmp;
        std::list<CGameObject> childObjects;
    private:

};

#endif // CGAMEOBJECT_H
