#ifndef CUBEGRAPHICS_H
#define CUBEGRAPHICS_H
#include "graphicscomponent.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <glm/vec3.hpp>

class CubeGraphics : public virtual GraphicsComponent
{
public:
    CubeGraphics();

    // GraphicsComponent interface
    void Update() override  ;
    void Init(Transform *) override;
private:
    Transform* transform_;
};

#endif // CUBEGRAPHICS_H
