#include "CGameEngine.h"

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

CGameEngine::CGameEngine()
{
    display = NULL;
    event_queue = NULL;
    timer = NULL;

    InitializeKeys();
    redraw = true;
    doexit = false;

}

CGameEngine::~CGameEngine()
{
    //dtor
}

void CGameEngine::Initialize()
{




    if(!al_init()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    if(!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize the keyboard!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    if(!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    display = al_create_display(SCREEN_W,SCREEN_H);
    if(!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_timer(timer);
        al_destroy_display(display);
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

}

void CGameEngine::Start()
{
    al_flip_display();
    //al_rest(5);
    al_start_timer(timer);

    while(!doexit) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }

/*        if(ev.type == ALLEGRO_EVENT_TIMER) {

            if(key[KEY_LEFT]) {
                space_ship_x -= 3;
            }
            else if (key[KEY_RIGHT]) {
                space_ship_x += 3;
            }

            redraw = true;
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            switch(ev.keyboard.keycode) {
                case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = true;
                break;

                case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = true;
                break;
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
            switch(ev.keyboard.keycode) {

                case ALLEGRO_KEY_LEFT:
                key[KEY_LEFT] = false;
                break;

                case ALLEGRO_KEY_RIGHT:
                key[KEY_RIGHT] = false;
                break;

                case ALLEGRO_KEY_ESCAPE:
                doexit = true;
                break;
            }
        }

        if(redraw && al_is_event_queue_empty(event_queue)) {
            redraw = false;

            al_clear_to_color(al_map_rgb(0,0,0));
            al_draw_bitmap(space_ship,space_ship_x,space_ship_y,0);
            al_draw_bitmap(enemy_ship1,200,400, 0);
            al_draw_bitmap(enemy_ship2,100,400, 0);
            al_draw_bitmap(enemy_ship3,300,400, 0);
            al_draw_bitmap(enemy_ship4,400,400, 0);
            al_flip_display();
        }*/

    }
}

void CGameEngine::Cleanup()
{
    al_destroy_display(this->display);
    /*al_destroy_bitmap(space_ship);
    al_destroy_bitmap(enemy_ship1);
    al_destroy_bitmap(enemy_ship2);
    al_destroy_bitmap(enemy_ship3);
    al_destroy_bitmap(enemy_ship4);*/
    al_destroy_timer(this->timer);
}

void CGameEngine::InitializeKeys()
{
    int i = 0;
    int length = 4;

    for(;i < length;i++) {
        this->key[i] = false;
    }
}
