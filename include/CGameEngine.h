#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H

#include <stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "CSceneManager.h"
#include "CRenderer.h"

class CGameEngine
{
    public:
        CGameEngine(CSceneManager *parScManager, CRenderer *parRenderer);
        virtual ~CGameEngine();
        void Initialize();
        void Start();
        void Cleanup();
    protected:
    private:
        ALLEGRO_DISPLAY *display;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_TIMER *timer;
        bool key[4];
        bool redraw;
        bool doexit;
        const float FPS = 60;


        CSceneManager *sceneManager;

        CRenderer *renderer;

        void InitializeKeys();
};

#endif // CGAMEENGINE_H
