#ifndef PHYSICSCOMPONENT_H
#define PHYSICSCOMPONENT_H

#include "rigidbody.h"
#include "collider.h"
#include "vector"
#include <memory>

class PhysicsComponent
{
public:
    PhysicsComponent();
    ~PhysicsComponent();

    void AddRigidbody();
    Rigidbody* getRigidbody(){return rigidbody_.get();}

    void AddCollider(Collider*);
    std::vector<Collider*> getColliders();

    void Update(void);
    void Init(Transform*);

    Transform* getTransform(){return transform_;}
private:
    std::unique_ptr<Rigidbody> rigidbody_;
    Transform* transform_;
    std::vector<Collider*> colliders_;
};

#endif // PHYSICSCOMPONENT_H
