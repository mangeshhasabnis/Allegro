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

void CScene::Draw()
{
    for(std::list<CGameObject>::iterator it = this->objects.begin(); it != this->objects.end(); ++it)
    {
        it->Draw();
    }
}
