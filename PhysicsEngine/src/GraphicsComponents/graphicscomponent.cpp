#include "graphicscomponent.h"

GraphicsComponent::GraphicsComponent()
{

}


void GraphicsComponent::Update()
{
    glm::vec3 position = transform_->GetPosition();
    glm::vec3 rotation = transform_->GetRotation();
    glm::vec3 scale = transform_->GetScale();


    glTranslatef(position[0], position[1], position[2]);


    glRotatef(glm::length(rotation), rotation.x, rotation.y, rotation.z);
    glScalef(scale[0], scale[1], scale[2]);

    Draw();
}

void GraphicsComponent::Draw()
{

}

void GraphicsComponent::Init(Transform *transform)
{
    transform_ = transform;
}
