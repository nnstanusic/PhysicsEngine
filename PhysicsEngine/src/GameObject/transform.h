#ifndef TRANSFORM_H
#define TRANSFORM_H

#include<glm/vec3.hpp>


class Transform
{
public:
    Transform();

    glm::vec3 GetPosition(void);
    glm::vec3 GetRotation(void);
    glm::vec3 GetScale(void);

    void Translate(glm::vec3);
    void Rotate(glm::vec3, float);
    void RotationAngles(glm::vec3);
    void Scale(glm::vec3);

private:
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);


};

#endif // TRANSFORM_H
