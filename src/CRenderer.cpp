#include "CRenderer.h"

using namespace std;

CRenderer::CRenderer()
{
    //ctor
}

CRenderer::~CRenderer()
{
    //dtor
}

void CRenderer::Draw(CScene *scene)
{
    list<CGameObject> objects = scene->GetGameObjects();

    for(list<CGameObject>::iterator it = objects.begin(); it != objects.end(); ++it)
    {

    }
}
