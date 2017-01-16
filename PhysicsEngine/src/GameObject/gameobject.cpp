#include "gameobject.h"
#include <iostream>

GameObject::GameObject(std::unique_ptr<Transform> transform)
{
    transform_ = std::move(transform);
    ai_ = nullptr;
    physics_ = nullptr;
    graphics_ = nullptr;
}

GameObject::GameObject(std::unique_ptr<Transform> transform,
                       std::unique_ptr<AIComponent> ai,
                       std::unique_ptr<PhysicsComponent> physics,
                       std::unique_ptr<GraphicsComponent> graphics)
{ 
    transform_ = std::move(transform);
    graphics_ = std::move(graphics);
    physics_ = std::move(physics);
    ai_ = std::move(ai);

    if(graphics_ != nullptr)
        graphics_->Init(transform_.get());
    if(physics_ != nullptr)
        physics_->Init(transform_.get());
    if(ai_ != nullptr)
        ai_->Init(transform_.get());

}


GameObject::~GameObject()
{

}

void GameObject::Update()
{
    ai_->Update();
    physics_->Update();
    graphics_->Update();

}

void GameObject::SetAIComponent
    (std::unique_ptr<AIComponent> AIComponent)
{
    ai_ = std::move(AIComponent);
}

void GameObject::SetPhysicsComponent
    (std::unique_ptr<PhysicsComponent> physicsComponent)
{
    physics_ = std::move(physicsComponent);
    physics_->Init(transform_.get());
}

void GameObject::SetGraphicsComponent
    (std::unique_ptr<GraphicsComponent> graphicsComponent)
{
    graphics_ = std::move(graphicsComponent);
    graphics_->Init(transform_.get());
}

Transform* GameObject::GetTransformComponent()
{
    return transform_.get();
}

AIComponent* GameObject::GetAIComponent()
{
    return ai_.get();
}

GraphicsComponent* GameObject::GetGraphicsComponent()
{
    return graphics_.get();
}

PhysicsComponent* GameObject::GetPhysicsComponent()
{
    return physics_.get();
}
