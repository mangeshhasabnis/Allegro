#include "CGameEngine.h"

int main(int argc, char **argv) {

    CGameEngine *engine = new CGameEngine();

    engine->Initialize();
    engine->Start();
    engine->Cleanup();

    return 0;
}



