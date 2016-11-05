#ifndef CRENDERER_H
#define CRENDERER_H

#include "CScene.h"
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class CRenderer
{
    public:
        CRenderer();
        virtual ~CRenderer();
        void Draw(CScene * scene);
    protected:
    private:
};

#endif // CRENDERER_H
