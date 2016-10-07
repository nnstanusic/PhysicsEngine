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
    void Update() override  ;
    void Init(Transform *) override;
private:
    Transform* transform_;

};

#endif // TRIANGLEGRAPHICS_H
