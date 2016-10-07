#include "physicscomponent.h"


PhysicsComponent::PhysicsComponent()
{

}

PhysicsComponent::~PhysicsComponent()
{

}

void PhysicsComponent::AddRigidbody()
{
    rigidbody_.reset(new Rigidbody());
    rigidbody_->Init(transform_);
}

void PhysicsComponent::AddCollider(Collider *collider)
{
    colliders_.push_back(collider);
}

std::vector<Collider*> PhysicsComponent::getColliders()
{
    return colliders_;
}

void PhysicsComponent::Update()
{
    if(rigidbody_)
        rigidbody_->Update();

}

void PhysicsComponent::Init(Transform* transform )
{

    transform_ = transform;
}
