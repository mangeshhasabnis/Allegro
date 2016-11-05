#include "CRenderer.h"

using namespace std;

CRenderer::CRenderer()
{
    //ctor
}

CRenderer::~CRenderer()
{
    al_destroy_display(this->display);
}

void CRenderer::Draw(CScene *scene)
{
    list<CGameObject> objects = scene->GetGameObjects();
    CGameObject object;

    for(list<CGameObject>::iterator it = objects.begin(); it != objects.end(); ++it)
    {
        object = *it;
        al_draw_bitmap(object.objectBmp, object.xlocation, object.ylocation, 0);
    }
    al_flip_display();
}

void CRenderer::Initialize()
{
    display = al_create_display(SCREEN_W,SCREEN_H);
    if(!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }
}

void CRenderer::RegisterEventSource(ALLEGRO_EVENT_QUEUE * event_queue)
{
    al_register_event_source(event_queue, al_get_display_event_source(this->display));
}
