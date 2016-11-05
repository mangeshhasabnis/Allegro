#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
    this->xlocation = 200;
    this->ylocation = 200;
    this->objectBmp = al_load_bitmap("/home/mangesh/Coding/GameDev/Allegro/spaceship.png");

    if(!this->objectBmp) {
        fprintf(stderr, "failed to load image!\n");
    }
}

SpaceShip::~SpaceShip()
{
    al_destroy_bitmap(this->objectBmp);
}
