#include "CScene.h"

CScene::CScene()
{
    //ctor
}

CScene::~CScene()
{
    //dtor
}

void CScene::AddGameObject(CGameObject &gameObject)
{
    this->objects.push_back(gameObject);
}

std::list<CGameObject> CScene::GetGameObjects()
{
    return this->objects;
}
