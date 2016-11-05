#include "CGameEngine.h"

int main(int argc, char **argv) {


    CSceneManager *sceneManager = new CSceneManager();
    CRenderer *renderer = new CRenderer();


    CGameEngine *engine = new CGameEngine(sceneManager, renderer);

    engine->Initialize();
    engine->Start();
    engine->Cleanup();

    return 0;
}



