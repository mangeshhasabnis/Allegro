#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H

#include <stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "CSceneManager.h"

class CGameEngine
{
    public:
        CGameEngine();
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
        const int SCREEN_W = 800;
        const int SCREEN_H = 600;

        CSceneManager *sceneManager;

        void InitializeKeys();
};

#endif // CGAMEENGINE_H
