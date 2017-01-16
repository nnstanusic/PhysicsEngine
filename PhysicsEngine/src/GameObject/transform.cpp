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

void Transform::SetPosiotion(glm::vec3 vector)
{
    position = vector;
}

void Transform::Rotate(glm::vec3 axis, float angle)
{
    rotation = glm::normalize(axis) * angle;
}

void Transform::SetRotation(glm::vec3 vector)
{
    rotation = vector;
}


void Transform::Scale(glm::vec3 vector)
{
    scale = vector;
}

void Transform::Print(glm::vec3 vector)
{
    std::cout << vector[0] << " "
              << vector[1] << " "
              << vector[2] << std::endl;
}

void Transform::Print(glm::vec4 vector)
{
    std::cout << vector[0] << " "
              << vector[1] << " "
              << vector[2] << " "
              << vector[3] << std::endl;
}
