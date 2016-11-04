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

/*void CSceneManager::Update()
{


}*/
