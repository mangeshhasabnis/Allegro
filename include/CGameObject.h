#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H

#include <list>

class CGameObject
{
    public:
        CGameObject();
        virtual ~CGameObject();
        virtual void Draw();
    protected:
    private:
        int xlocation;
        int ylocation;
        std::list<CGameObject> childObjects;
};

#endif // CGAMEOBJECT_H
