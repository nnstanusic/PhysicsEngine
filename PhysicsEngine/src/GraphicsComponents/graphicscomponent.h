#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H
#include "transform.h"

class GraphicsComponent
{
public:
    GraphicsComponent();
    virtual void Init(Transform*) = 0;
    virtual void Update() = 0;
};

#endif // GRAPHICSCOMPONENT_H
