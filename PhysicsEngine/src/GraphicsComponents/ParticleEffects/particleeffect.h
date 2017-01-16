#ifndef PARTICLEEFFECT_H
#define PARTICLEEFFECT_H

#include "graphicscomponent.h"

class ParticleEffect: public virtual GraphicsComponent
{
public:
    ParticleEffect();

    // GraphicsComponent interface
    void Draw();

};

#endif // PARTICLEEFFECT_H
