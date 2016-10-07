#include "sphere.h"

Sphere::Sphere()
{

}

void Sphere::Update()
{

    glm::vec3 position = transform_->GetPosition();
    glm::vec3 rotation = transform_->GetRotation();
    glm::vec3 scale = transform_->GetScale();


    glTranslatef(position[0], position[1], position[2]);


    glRotatef(rotation[0], 1,0,0);
    glRotatef(rotation[1], 0,1,0);
    glRotatef(rotation[2], 0,0,1);


    glScalef(scale[0], scale[1], scale[2]);

    glutSolidSphere(1, 50, 50);

}

void Sphere::Init(Transform *transform)
{
    transform_ = transform;
}
