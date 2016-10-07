#ifndef WORLD_H
#define WORLD_H
#include "vector"
#include "gameobject.h"
#include "spherecollider.h"
#include <GL/gl.h>
#include <glm/vec3.hpp>
#include <glm/geometric.hpp>
#include <vector>
#include <utility>

#include <iostream>
#include <typeinfo>


class World
{
public:
    World();
    void AddGameobject(GameObject *);
    void RemoveGameobject(GameObject *);
    void Update(void);

    std::pair<bool, glm::vec3>
        resolveCollision(Collider* , Collider*,
                         Transform *, Transform*);
    std::pair<bool, glm::vec3>
        resolveCollision(SphereCollider*, SphereCollider*,
                         Transform*, Transform*);
private:
    std::vector<GameObject*> objects_;
    std::vector<GraphicsComponent*> graphicsComponents_;
    std::vector<InputComponent*> inputComponents_;
    std::vector<PhysicsComponent*> physicsComponents_;
};

#endif // WORLD_H
