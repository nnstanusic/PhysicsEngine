#ifndef TRIANGLEGRAPHICS_H
#define TRIANGLEGRAPHICS_H
#include "graphicscomponent.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <glm/vec3.hpp>

class TriangleGraphics : public virtual GraphicsComponent
{
public:
    TriangleGraphics();
    void Draw() override  ;

};

#endif // TRIANGLEGRAPHICS_H
