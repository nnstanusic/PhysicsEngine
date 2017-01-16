#ifndef COORDINATESYSTEM_H
#define COORDINATESYSTEM_H

#include "graphicscomponent.h"
#include <GL/glut.h>
#include <GL/gl.h>

#include<iostream>
class CoordinateSystem : public virtual GraphicsComponent
{
public:
    CoordinateSystem();
    void Draw() override;

};

#endif // COORDINATESYSTEM_H
