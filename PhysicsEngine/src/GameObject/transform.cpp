#include "transform.h"

Transform::Transform()
{

}



glm::vec3 Transform::GetPosition()
{
    return position;
}

glm::vec3 Transform::GetRotation()
{
    return rotation;
}

glm::vec3 Transform::GetScale()
{
    return scale;
}

void Transform::Translate(glm::vec3 vector)
{
    position += vector;
}

void Transform::Rotate(glm::vec3 axis, float angle)
{

}

void Transform::RotationAngles(glm::vec3 vector)
{
    rotation += vector;
}


void Transform::Scale(glm::vec3 vector)
{
    scale = scale;
}
