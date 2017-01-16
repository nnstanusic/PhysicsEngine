#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "aicomponent.h"
#include "graphicscomponent.h"
#include "physicscomponent.h"
#include "transform.h"
#include <memory>
class GameObject
{
public:

    GameObject(std::unique_ptr<Transform>);
    GameObject(std::unique_ptr<Transform>,
               std::unique_ptr<AIComponent>,
               std::unique_ptr<PhysicsComponent>,
               std::unique_ptr<GraphicsComponent>);

    ~GameObject();


    void Update(void);

    void SetAIComponent(std::unique_ptr<AIComponent>);
    void SetPhysicsComponent(std::unique_ptr<PhysicsComponent>);
    void SetGraphicsComponent(std::unique_ptr<GraphicsComponent>);


    Transform* GetTransformComponent(void);
    AIComponent* GetAIComponent(void);
    PhysicsComponent* GetPhysicsComponent(void);
    GraphicsComponent* GetGraphicsComponent(void);


private:
    std::unique_ptr<Transform> transform_;
    std::unique_ptr<AIComponent> ai_;
    std::unique_ptr<PhysicsComponent> physics_;
    std::unique_ptr<GraphicsComponent> graphics_;


};

#endif // GAMEOBJECT_H
