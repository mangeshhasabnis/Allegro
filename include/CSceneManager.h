#ifndef CSCENEMANAGER_H
#define CSCENEMANAGER_H

#include <list>
#include "CScene.h"

class CSceneManager
{
    public:
        CSceneManager();
        virtual ~CSceneManager();
        void AddScene(CScene &scene);
        //void Update();
    protected:
    private:
        std::list<CScene> scenes;
};

#endif // CSCENEMANAGER_H
