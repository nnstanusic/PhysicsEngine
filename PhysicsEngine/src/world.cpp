#include "world.h"

World::World()
{

}

void World::AddGameobject(GameObject *gameObject)
{

    objects_.push_back(gameObject);
    graphicsComponents_.push_back(gameObject->GetGraphicsComponent());
    AIComponents_.push_back(gameObject->GetAIComponent());
    physicsComponents_.push_back(gameObject->GetPhysicsComponent());


}

void World::Update()
{


    for(AIComponent* input : AIComponents_)
    {
        if(input)
            input->Update();
    }

    for(PhysicsComponent* physics : physicsComponents_)
    {
        if(physics)
        {

            //colision selection
            //TODO daj jarane uljepsaj ovo nemoj brute forceat
            for(PhysicsComponent* target : physicsComponents_)
            {
                if(target != physics && target)
                {
                    for(auto collider1 : physics->getColliders())
                    {
                        for(auto collider2 : target->getColliders())
                        {
                            auto collisionPoint = resolveCollision(collider1,
                                                                   collider2,
                                                     physics->getTransform(),
                                                     target->getTransform());
                            if(collisionPoint.first)
                            {
                                target->getRigidbody()
                                      ->Bounce(collisionPoint.second);
                            }
                        }
                    }

                }
            }
            //force manipulation

            //rotation torque


            physics->Update();
        }
    }


    for(GraphicsComponent* graphics : graphicsComponents_)
    {

        if(graphics)
        {

            glPushMatrix();
            graphics->Update();
            glPopMatrix();
        }
    }
}


