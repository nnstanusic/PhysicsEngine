#include "gameobject.h"
#include <iostream>

GameObject::GameObject(std::unique_ptr<Transform> transform)
{
    transform_ = std::move(transform);
    input_ = nullptr;
    physics_ = nullptr;
    graphics_ = nullptr;
}

GameObject::GameObject(std::unique_ptr<Transform> transform,
                       std::unique_ptr<InputComponent> input,
                       std::unique_ptr<PhysicsComponent> physics,
                       std::unique_ptr<GraphicsComponent> graphics)
{ 
    transform_ = std::move(transform);
    graphics_ = std::move(graphics);
    physics_ = std::move(physics);
    input_ = std::move(input);
    graphics_->Init(transform_.get());
    physics_->Init(transform_.get());
}




GameObject::~GameObject()
{

}

void GameObject::PrintSomeShit()
{
    std::cout << "SomeShit";
}

void GameObject::Update()
{
    input_->Update();
    physics_->Update();

    graphics_->Update();

}

void GameObject::SetInputComponent
    (std::unique_ptr<InputComponent> inputComponent)
{
    input_ = std::move(inputComponent);
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

InputComponent* GameObject::GetInputComponent()
{
    return input_.get();
}

GraphicsComponent* GameObject::GetGraphicsComponent()
{
    return graphics_.get();
}

PhysicsComponent* GameObject::GetPhysicsComponent()
{
    return physics_.get();
}
