#include "CSceneManager.h"

CSceneManager::CSceneManager()
{

}

CSceneManager::~CSceneManager()
{
    //dtor
}

void CSceneManager::AddScene(CScene &scene)
{
    this->scenes.push_back(scene);
}

CScene * CSceneManager::GetCurrentScene()
{
    CScene * currentScene = NULL;

    if (this->scenes.size() > 0)
    {
        currentScene = &(this->scenes.front());
    }

    return currentScene;
}

/*void CSceneManager::Update()
{


}*/
