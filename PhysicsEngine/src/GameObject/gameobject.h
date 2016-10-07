#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "inputcomponent.h"
#include "graphicscomponent.h"
#include "physicscomponent.h"
#include "transform.h"
#include <memory>
class GameObject
{
public:

    GameObject(std::unique_ptr<Transform>);
    GameObject(std::unique_ptr<Transform>,
               std::unique_ptr<InputComponent>,
               std::unique_ptr<PhysicsComponent>,
               std::unique_ptr<GraphicsComponent>);

    ~GameObject();

    void PrintSomeShit(void);
    void Update(void);

    void SetInputComponent(std::unique_ptr<InputComponent>);
    void SetPhysicsComponent(std::unique_ptr<PhysicsComponent>);
    void SetGraphicsComponent(std::unique_ptr<GraphicsComponent>);


    Transform* GetTransformComponent(void);
    InputComponent* GetInputComponent(void);
    PhysicsComponent* GetPhysicsComponent(void);
    GraphicsComponent* GetGraphicsComponent(void);


private:
    std::unique_ptr<Transform> transform_;
    std::unique_ptr<InputComponent> input_;
    std::unique_ptr<PhysicsComponent> physics_;
    std::unique_ptr<GraphicsComponent> graphics_;


};

#endif // GAMEOBJECT_H
