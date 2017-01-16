#ifndef GRAPHICSCOMPONENT_H
#define GRAPHICSCOMPONENT_H
#include "transform.h"
#include <GL/gl.h>
class GraphicsComponent
{
public:
    GraphicsComponent();
    virtual void Draw();

    void Init(Transform*);
    void Update();

protected:
    Transform* transform_;
};

#endif // GRAPHICSCOMPONENT_H
