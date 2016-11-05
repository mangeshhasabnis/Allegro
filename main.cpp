#include "CGameEngine.h"
#include "SpaceShip.h"

int main(int argc, char **argv) {


    CSceneManager *sceneManager = new CSceneManager();
    CRenderer *renderer = new CRenderer();

    CGameEngine *engine = new CGameEngine(sceneManager, renderer);

    engine->Initialize();

    /*Creating a scene*/
    SpaceShip * ship = new SpaceShip();
    CScene * scene = new CScene();
    scene->AddGameObject(*ship);

    /*Adding scene to scene manager*/
    sceneManager->AddScene(*scene);



    engine->Start();
    engine->Cleanup();

    return 0;
}



