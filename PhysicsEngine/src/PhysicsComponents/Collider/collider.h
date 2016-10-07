#ifndef COLLIDER_H
#define COLLIDER_H
#include <glm/vec3.hpp>

class Collider
{
public:
    Collider();
    virtual void Update() = 0;
    glm::vec3 getOffsetFromCentre(){return offset;}
    void setOffsetFromCentre(glm::vec3);
private:
    glm::vec3 offset;
};

#endif // COLLIDER_H
