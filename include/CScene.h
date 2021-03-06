#ifndef CSCENE_H
#define CSCENE_H

#include "CGameObject.h"
#include <list>

class CScene
{
    public:
        CScene();
        virtual ~CScene();
        void AddGameObject(CGameObject &gameObject);
        std::list<CGameObject> GetGameObjects();
    protected:
    private:
        std::list<CGameObject> objects;
};

#endif // CSCENE_H
