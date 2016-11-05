#ifndef CRENDERER_H
#define CRENDERER_H

#include "CScene.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

class CRenderer
{
    public:
        CRenderer();
        virtual ~CRenderer();
        void Draw(CScene * scene);
        void Initialize();
        void RegisterEventSource(ALLEGRO_EVENT_QUEUE *event_queue);
    protected:
    private:
        ALLEGRO_DISPLAY *display;
        const int SCREEN_W = 800;
        const int SCREEN_H = 600;
};

#endif // CRENDERER_H
