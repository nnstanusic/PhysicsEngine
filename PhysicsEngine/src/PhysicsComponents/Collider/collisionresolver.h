#ifndef COLLISIONRESOLVER_H
#define COLLISIONRESOLVER_H

#include <utility>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <spherecollider.h>
#include <gameobject.h>


static inline std::pair<bool, glm::vec3>
    resolveSphereCollision(SphereCollider *Coll, SphereCollider *Coll2,
                            Transform* trans1 , Transform* trans2)
{

    glm::vec3 coord1 = trans1->GetPosition() + Coll->getOffsetFromCentre();
    glm::vec3 coord2 = trans2->GetPosition() + Coll2->getOffsetFromCentre();

    float distance = glm::distance(coord1, coord2);

    bool isCollision = distance <= std::abs(Coll->radius + Coll2->radius);

    glm::vec3 collisionPoint = coord1 + 0.5f * distance *
                               (glm::normalize(coord2 - coord1));

    std:: cout<< std::endl;
    return {isCollision, collisionPoint};
}



static inline std::pair<bool, glm::vec3>
    resolveCollision(Collider* coll1, Collider* coll2,
                            Transform* trans1, Transform* trans2 )
{

    if(typeid(*coll1) == typeid(SphereCollider))
    {
        if(typeid(*coll2) == typeid(SphereCollider))
        {

            return resolveSphereCollision((SphereCollider*)coll1,
                                          (SphereCollider*)coll2,
                                          trans1,
                                          trans2);
        }
    }

    return {false, glm::vec3(0,0,0)} ;
}

#endif // COLLISIONRESOLVER_H
