#include <stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

enum MYKEYS {
   KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

const float FPS = 60;
const int SCREEN_W = 800;
const int SCREEN_H = 600;

int main(int argc, char **argv) {

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_BITMAP  *space_ship   = NULL;
    float space_ship_x = SCREEN_W / 2;
    float space_ship_y = SCREEN_H / 2;

    ALLEGRO_BITMAP  *enemy_ship1 = NULL;
    ALLEGRO_BITMAP  *enemy_ship2 = NULL;
    ALLEGRO_BITMAP  *enemy_ship3 = NULL;
    ALLEGRO_BITMAP  *enemy_ship4 = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;
    ALLEGRO_TIMER   *timer = NULL;

    bool key[4] = { false, false, false, false };

    bool redraw = true;
    bool doexit = false;

    if(!al_init()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize allegro!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize the keyboard!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create timer!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    if(!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return 0;
    }

    display = al_create_display(SCREEN_W,SCREEN_H);
    if(!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_timer(timer);
        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    space_ship = al_load_bitmap("spaceship.png");
    enemy_ship1 = al_load_bitmap("enemyspaceship2.jpg");
    enemy_ship2 = al_load_bitmap("enemyspaceship3.jpg");
    enemy_ship3 = al_load_bitmap("enemyspaceship4.jpg");
    enemy_ship4 = al_load_bitmap("enemyspaceship5.jpg");

    if(!space_ship || !enemy_ship1 || !enemy_ship2 || !enemy_ship3 || !enemy_ship4) {
        al_show_native_message_box(display, "Error", "Error", "Failed to load image!",
                                 NULL, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_timer(timer);
        al_destroy_display(display);
        return 0;
    }

    al_draw_bitmap(space_ship,space_ship_x,space_ship_y,0);
    al_draw_bitmap(enemy_ship1,200,400, 0);
    al_draw_bitmap(enemy_ship2,100,400, 0);
    al_draw_bitmap(enemy_ship3,300,400, 0);
    al_draw_bitmap(enemy_ship4,400,400, 0);

    al_flip_display();
    //al_rest(5);
    al_start_timer(timer);

    while(!doexit) {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER) {

            if(key[KEY_LEFT]) {
                space_ship_x -= 2;
            }
            else if (key[KEY_RIGHT]) {
                space_ship_x += 2;
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
                /*case ALLEGRO_KEY_UP:
                key[KEY_UP] = false;
                break;

                case ALLEGRO_KEY_DOWN:
                key[KEY_DOWN] = false;
                break;*/

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
        }

    }

    al_destroy_display(display);
    al_destroy_bitmap(space_ship);
    al_destroy_bitmap(enemy_ship1);
    al_destroy_bitmap(enemy_ship2);
    al_destroy_bitmap(enemy_ship3);
    al_destroy_bitmap(enemy_ship4);
    al_destroy_timer(timer);

    return 0;
}



