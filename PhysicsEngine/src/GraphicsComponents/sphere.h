#ifndef SPHERE_H
#define SPHERE_H
#include "graphicscomponent.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <glm/vec3.hpp>


class Sphere : public virtual GraphicsComponent
{
public:
    Sphere();

    // GraphicsComponent interface
    void Draw() override  ;


};

#endif // SPHERE_H
