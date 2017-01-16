#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "graphicscomponent.h"
#include <GL/glut.h>
#include <GL/gl.h>


class Rectangle : public virtual GraphicsComponent
{
public:
    Rectangle();
    void Draw() override  ;
};

#endif // RECTANGLE_H
