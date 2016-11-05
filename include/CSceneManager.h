#ifndef CSCENEMANAGER_H
#define CSCENEMANAGER_H

#include <list>
#include "CScene.h"
#include <cstddef>

class CSceneManager
{
    public:
        CSceneManager();
        virtual ~CSceneManager();
        void AddScene(CScene &scene);
        CScene * GetCurrentScene();
        //void Update();
    protected:
    private:
        std::list<CScene> scenes;
};

#endif // CSCENEMANAGER_H
