#ifndef CGAMEOBJECT_H
#define CGAMEOBJECT_H

#include <list>

class CGameObject
{
    public:
        CGameObject();
        virtual ~CGameObject();
    protected:
    private:
        int xlocation;
        int ylocation;
        std::list<CGameObject> childObjects;
};

#endif // CGAMEOBJECT_H
