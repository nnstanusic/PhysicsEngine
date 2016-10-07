#ifndef SPHERE_H
#define SPHERE_H
#include "graphicscomponent.h"
#include <GL/glut.h>
#include <GL/gl.h>
#include <glm/vec3.hpp>

#include<iostream>

class Sphere : public virtual GraphicsComponent
{
public:
    Sphere();

    // GraphicsComponent interface
    void Update() override  ;
    void Init(Transform *) override;
private:
    Transform* transform_;
};

#endif // SPHERE_H
