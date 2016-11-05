#include "SpaceShip.h"

SpaceShip::SpaceShip()
{
    this->xlocation = 200;
    this->ylocation = 200;
    this->spaceShipBmp = al_load_bitmap("./spaceship.png");
}

SpaceShip::~SpaceShip()
{
    al_destroy_bitmap(this->spaceShipBmp);
}
